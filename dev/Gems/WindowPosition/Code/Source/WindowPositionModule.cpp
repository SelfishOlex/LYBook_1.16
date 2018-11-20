#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <WindowPositionCommands.h>
#include <CrySystemBus.h>
#include <platform.h>
#include <platform_impl.h>

namespace WindowPosition
{
    class WindowPositionModule
        : public AZ::Module
        , public CrySystemEventBus::Handler
    {
    public:
        AZ_RTTI(WindowPositionModule,
            "{674A19AA-CC50-4C49-A5ED-44C316F84BC8}", AZ::Module);
        AZ_CLASS_ALLOCATOR(WindowPositionModule,
            AZ::SystemAllocator, 0);

        WindowPositionModule() : AZ::Module()
        {
            CrySystemEventBus::Handler::BusConnect();
        }

        ~WindowPositionModule()
        {
            CrySystemEventBus::Handler::BusDisconnect();
        }

        void OnCrySystemInitialized(ISystem&,
            const SSystemInitParams&) override
        {
            m_commands.Register();
        }

        void OnCrySystemShutdown(ISystem&) override
        {
            m_commands.Unregister();
        }

        WindowPositionCommands m_commands;
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(
    WindowPosition_1d5b9f4599f9452491aa0f9edf53688c,
    WindowPosition::WindowPositionModule)
