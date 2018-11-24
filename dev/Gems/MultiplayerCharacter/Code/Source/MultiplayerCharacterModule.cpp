#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <MultiplayerCharacterSystemComponent.h>
#include <CameraControlsComponent.h>
#include <InputCaptureComponent.h>
#include <PlayerControlsComponent.h>
#include <PebbleSpawnerComponent.h>
#include <TimedProjectileComponent.h>
#include <FootstepComponent.h>
#include <LocalClientComponent.h>
#include <ServerAuthPlayerComponent.h>
#include <ServerPlayerSpawnerComponent.h>
#include <PlayerActionRelayComponent.h>
#include <platform_impl.h>

namespace MultiplayerCharacter
{
    class MultiplayerCharacterModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MultiplayerCharacterModule, "{7F5C6EBE-99E0-42E7-B817-B304C2A23F2C}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MultiplayerCharacterModule, AZ::SystemAllocator, 0);

        MultiplayerCharacterModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                CameraControlsComponent::CreateDescriptor(),
                FootstepComponent::CreateDescriptor(),
                InputCaptureComponent::CreateDescriptor(),
                PebbleSpawnerComponent::CreateDescriptor(),
                PlayerControlsComponent::CreateDescriptor(),
                TimedProjectileComponent::CreateDescriptor(),
                LocalClientComponent::CreateDescriptor(),
                ServerAuthPlayerComponent::CreateDescriptor(),
                ServerPlayerSpawnerComponent::CreateDescriptor(),
                PlayerActionRelayComponent::CreateDescriptor(),
                MultiplayerCharacterSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MultiplayerCharacterSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(MultiplayerCharacter_27216e65cdcc466294f1ce1c6da72521, MultiplayerCharacter::MultiplayerCharacterModule)
