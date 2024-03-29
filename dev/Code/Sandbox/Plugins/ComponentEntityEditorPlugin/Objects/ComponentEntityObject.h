/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#ifndef CRYINCLUDE_COMPONENTENTITYEDITORPLUGIN_COMPONENTENTITYOBJECT_H
#define CRYINCLUDE_COMPONENTENTITYEDITORPLUGIN_COMPONENTENTITYOBJECT_H
#pragma once

#include <AzCore/Component/TransformBus.h>
#include <AzCore/Component/EntityBus.h>
#include <AzToolsFramework/API/ToolsApplicationAPI.h>
#include <AzToolsFramework/API/ComponentEntityObjectBus.h>
#include <AzToolsFramework/ToolsComponents/EditorLockComponentBus.h>
#include <AzToolsFramework/ToolsComponents/EditorVisibilityBus.h>
#include <AzToolsFramework/ToolsComponents/EditorEntityIconComponentBus.h>
#include <AzToolsFramework/UI/PropertyEditor/PropertyEditorAPI.h>

#include "../Editor/Objects/EntityObject.h"
#include <LmbrCentral/Rendering/MeshComponentBus.h>

class QMenu;

/**
* Sandbox representation of component entities (AZ::Entity).
*/
class CComponentEntityObject
    : public CEntityObject
    , private AzToolsFramework::EntitySelectionEvents::Bus::Handler
    , private AzToolsFramework::EditorLockComponentNotificationBus::Handler
    , private AzToolsFramework::EditorVisibilityNotificationBus::Handler
    , private AzToolsFramework::EditorEntityIconComponentNotificationBus::Handler
    , private AZ::TransformNotificationBus::Handler
    , private LmbrCentral::MeshComponentNotificationBus::Handler
    , private AzToolsFramework::ComponentEntityEditorRequestBus::Handler
    , private AzToolsFramework::ComponentEntityObjectRequestBus::Handler
    , private AZ::EntityBus::Handler
{
public:
    ~CComponentEntityObject();

    //////////////////////////////////////////////////////////////////////////
    // Overrides from CEntityObject/CBaseObject.
    //////////////////////////////////////////////////////////////////////////
    bool Init(IEditor* ie, CBaseObject* prev, const QString& file) override;
    void InitVariables() override {};
    bool SetPos(const Vec3& pos, int flags = 0) override;
    bool SetRotation(const Quat& rotate, int flags) override;
    bool SetScale(const Vec3& scale, int flags) override;
    void InvalidateTM(int nWhyFlags) override;
    void Display(DisplayContext& disp) override;
    void OnContextMenu(QMenu* pMenu) override;
    int MouseCreateCallback(CViewport* view, EMouseEvent event, QPoint& point, int flags) override;
    bool HitHelperTest(HitContext& hc) override;
    bool HitTest(HitContext& hc) override;
    void GetLocalBounds(AABB& box) override;
    void GetBoundBox(AABB& box) override;
    void SetName(const QString& name) override;
    bool IsFrozen() const override;
    void SetFrozen(bool bFrozen) override;
    void SetHidden(bool bHidden, uint64 hiddenId = CBaseObject::s_invalidHiddenID, bool bAnimated = false) override;
    void UpdateVisibility(bool bVisible) override;
    void SetSelected(bool bSelect) override;
    void SetHighlight(bool bHighlight) override;
    IRenderNode* GetEngineNode() const override;
    void AttachChild(CBaseObject* child, bool bKeepPos = true) override;
    void DetachAll(bool bKeepPos = true) override;
    void DetachThis(bool bKeepPos = true) override;
    CBaseObject* GetLinkParent() const override;
    bool SupportsLayers() const override { return false; }
    void OnLayerChanged(CObjectLayer* layer) override;
    XmlNodeRef Export(const QString& levelPath, XmlNodeRef& xmlNode) override;
    void DeleteEntity() override;
    void SetMaterial(CMaterial* mtl) override;
    CMaterial* GetMaterial() const override;
    CMaterial* GetRenderMaterial() const override;
    void DrawDefault(DisplayContext& dc, const QColor& labelColor = QColor(255, 255, 255)) override;
    IStatObj* GetIStatObj() override;
    bool IsIsolated() const override;

    // Always returns false as Component entity highlighting (accenting) is taken care of elsewhere
    bool IsHighlighted() { return false; }
    // Component entity highlighting (accenting) is taken care of elsewhere
    void DrawHighlight(DisplayContext& /*dc*/) {};

    // Don't auto-clone children. Cloning happens in groups with reference fixups,
    // and individually selected objercts should be cloned as individuals.
    bool ShouldCloneChildren() const override { return false; }

    // For now, dont allow Component entities to be grouped
    bool IsGroupable() override { return false; }


    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // AZ::EntityBus::Handler
    void OnEntityNameChanged(const AZStd::string& name) override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //! AzToolsFramework::EntitySelectionEvents::Bus::Handler
    void OnSelected() override;
    void OnDeselected() override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // AzToolsFramework::EditorLockComponentNotificationBus::Handler
    void OnEntityLockChanged(bool locked) override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // AzToolsFramework::EditorVisibilityNotificationBus::Handler
    void OnEntityVisibilityFlagChanged(bool flag) override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // AzToolsFramework::EditorEntityIconComponentNotificationBus::Handler
    void OnEntityIconChanged(const AZ::Data::AssetId& entityIconAssetId) override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //! AZ::TransformNotificationBus::Handler
    void OnTransformChanged(const AZ::Transform& local, const AZ::Transform& world) override;
    void OnParentChanged(AZ::EntityId oldParent, AZ::EntityId newParent) override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //! MeshComponentNotificationBus
    void OnMeshCreated(const AZ::Data::Asset<AZ::Data::AssetData>& asset) override;
    void OnBoundsReset() override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //! ComponentEntityEditorRequestBus
    CEntityObject* GetSandboxObject() override { return this; }
    bool IsSandboxObjectHighlighted() override { return IsHighlighted(); }
    void SetSandboxObjectAccent(AzToolsFramework::EntityAccentType accent) override;
    void SetSandBoxObjectIsolated(bool isIsolated) override;
    bool IsSandBoxObjectIsolated() override;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //! ComponentEntityObjectRequestBus
    AZ::EntityId GetAssociatedEntityId() override { return m_entityId; }
    //////////////////////////////////////////////////////////////////////////

    void AssignEntity(AZ::Entity* entity, bool destroyOld = true);

    bool IsEntityIconVisible() const { return m_entityIconVisible; }

    static CComponentEntityObject* FindObjectForEntity(AZ::EntityId id);

protected:
    friend class CTemplateObjectClassDesc<CComponentEntityObject>;
    friend class SandboxIntegrationManager;

    CComponentEntityObject();

    static const GUID& GetClassID()
    {
        // {70650EB8-B1BD-4DC8-AC28-7CD767D7BB30}
        static const GUID guid = {
            0x70650EB8, 0xB1BD, 0x4DC8, { 0xac, 0x28, 0x7c, 0xd7, 0x67, 0xd7, 0xbb, 0x30 }
        };
        return guid;
    }

    float GetRadius();

    void DeleteThis() { delete this; };

    bool IsAncestorSelected() const;

    bool IsAncestorIconDrawingAtSameLocation() const;

    bool IsDescendantSelectedAtSameLocation() const;

    void SetupEntityIcon();

    void DrawAccent(DisplayContext& dc);

    void ValidateMeshStatObject();

    //! Whether we have have a valid icon path in \ref m_icon
    bool m_hasIcon;

    //! Path to component entity icon for this object
    AZStd::string m_icon;
    ITexture* m_iconTexture;

    //! Whether this component entity icon is visible
    bool m_entityIconVisible;

    //! Whether to only use this object's icon for hit tests. When enabled, we ignore hit tests
    //! against the geometry of the object
    bool m_iconOnlyHitTest;

    //! Whether to draw accents for this object (accents include selection wireframe bounding boxes)
    bool m_drawAccents;

    //! Indicate if an entity is isolated when the editor is in Isolation Mode.
    bool m_isIsolated;

    //! Displays viewport icon for this entity.
    //! \returns whether an icon is being displayed
    bool DisplayEntityIcon(DisplayContext& dc);

    //! EntityId that this editor object represents/is tied to
    AZ::EntityId m_entityId;

    class EditorActionGuard
    {
    public:

        EditorActionGuard()
            : m_count(0) {}

        void Enter()    { ++m_count; }
        void Exit()     { --m_count; }

        //! \return true if the guard passes.
        operator bool() const {
            return m_count <= 0;
        }

    private:

        int m_count;
    };

    class EditorActionScope
    {
    public:

        EditorActionScope(EditorActionGuard& guard)
            : m_guard(guard)
        {
            m_guard.Enter();
        }

        ~EditorActionScope()
        {
            m_guard.Exit();
        }

    private:

        EditorActionGuard& m_guard;
    };

    EditorActionGuard m_lockedReentryGuard;
    EditorActionGuard m_nameReentryGuard;
    EditorActionGuard m_selectionReentryGuard;
    EditorActionGuard m_visibilityFlagReentryGuard;
    EditorActionGuard m_transformReentryGuard;
    EditorActionGuard m_parentingReentryGuard;

    AzToolsFramework::EntityAccentType m_accentType;
};

#endif // CRYINCLUDE_COMPONENTENTITYEDITORPLUGIN_COMPONENTENTITYOBJECT_H
