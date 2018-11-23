#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <MyProjectSystemComponent.h>
#include <MyComponent.h>
#include <OscillatorComponent.h>
#include <MySpawnerComponent.h>
#include <StartingMapSystemComponent.h>
#include <TransformSyncComponent.h>
#include <MyUIStatusComponents.h>
#include <MyScriptHelperComponent.h>

namespace MyProject
{
    class MyProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MyProjectModule,
            "{D42F0849-C3A8-4476-92BF-0D97340B067C}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MyProjectModule,
            AZ::SystemAllocator, 0);

        MyProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor()
            // into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MyProjectSystemComponent::CreateDescriptor(),
                MyComponent::CreateDescriptor(),
                OscillatorComponent::CreateDescriptor(),
                MySpawnerComponent::CreateDescriptor(),
                StartingMapSystemComponent::CreateDescriptor(),
                TransformSyncComponent::CreateDescriptor(),

                MyUIForwardComponent::CreateDescriptor(),
                MyUIBackwardComponent::CreateDescriptor(),
                MyUIStrafeLeftComponent::CreateDescriptor(),
                MyUIStrafeRightComponent::CreateDescriptor(),

                MyScriptHelperComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList
            GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MyProjectSystemComponent>(),
                azrtti_typeid<StartingMapSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class
AZ_DECLARE_MODULE_CLASS(MyProject_ebc264b367f841b6840b65ec4bd91a29,
    MyProject::MyProjectModule)
