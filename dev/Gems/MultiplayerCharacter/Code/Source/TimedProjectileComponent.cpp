#include "TimedProjectileComponent.h"
#include <AzCore/Serialization/EditContext.h>
#include <AzFramework/Entity/GameEntityContextBus.h>
#include <LmbrCentral/Physics/PhysicsComponentBus.h>
#include <AzFramework/Network/NetBindingHandlerBus.h>
#include <AzCore/Component/TransformBus.h>

using namespace AZ;
using namespace AzFramework;
using namespace MultiplayerCharacter;

void TimedProjectileComponent::Reflect(ReflectContext* context)
{
    if (auto sc = azrtti_cast<SerializeContext*>(context))
    {
        sc->Class<TimedProjectileComponent, Component>()
            ->Field("Initial Impulse",
                &TimedProjectileComponent::m_impulse)
            ->Field("Max Life",
                &TimedProjectileComponent::m_maxLifetime)
            ->Version(1);
        if (EditContext* ec = sc->GetEditContext())
        {
            ec->Class<TimedProjectileComponent>(
                "Timed Projectile",
                "Moves the object then deletes it")
                ->ClassElement(Edit::ClassElements::EditorData,
                    "")
                ->Attribute(Edit::Attributes::Category,
                    "Multiplayer Character")
                ->Attribute(Edit::Attributes::
                    AppearsInAddComponentMenu,
                    AZ_CRC("Game"))
                ->DataElement(nullptr,
                    &TimedProjectileComponent::m_impulse,
                    "Initial Impulse", "")
                ->DataElement(nullptr,
                    &TimedProjectileComponent::m_maxLifetime,
                    "Max Life", "");
        }
    }
}
void TimedProjectileComponent::Activate()
{
    if (NetQuery::IsEntityAuthoritative(GetEntityId()))
        TickBus::Handler::BusConnect();
}

void TimedProjectileComponent::Deactivate()
{
    TickBus::Handler::BusDisconnect();
}

void TimedProjectileComponent::OnTick(float dt, ScriptTimePoint)
{
    if (m_lifetime < 1.f)
    {
        AZ::Quaternion myRotation;
        TransformBus::EventResult(myRotation, GetEntityId(),
            &TransformBus::Events::GetWorldRotationQuaternion);
        // impulse in the direction of the pebble's orientation
        Vector3 dir = myRotation * AZ::Vector3::CreateAxisY(1.f);

        using PhysBus = LmbrCentral::PhysicsComponentRequestBus;
        PhysBus::Event( GetEntityId(),
            &PhysBus::Events::AddImpulse, dir * dt * m_impulse);
    }
    m_lifetime += dt;
    if (m_lifetime > m_maxLifetime) // life expired
    {
        TickBus::Handler::BusDisconnect();
        GameEntityContextRequestBus::Broadcast(
            &GameEntityContextRequestBus::Events::
                DestroyGameEntity, GetEntityId());
    }
}