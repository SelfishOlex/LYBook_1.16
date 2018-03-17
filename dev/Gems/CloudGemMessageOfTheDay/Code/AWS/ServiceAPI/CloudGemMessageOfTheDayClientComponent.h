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
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// THIS CODE IS AUTOGENERATED, DO NOT MODIFY
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/Component/Entity.h>
#include <AzCore/Component/ComponentBus.h>
#include <AzCore/EBus/EBus.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/smart_ptr/make_shared.h>
#include <AzCore/std/smart_ptr/shared_ptr.h>
#include <AzCore/std/string/conversions.h>

#if defined (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)
#include <aws/core/http/HttpRequest.h>
#include <aws/core/http/HttpResponse.h>
#endif // (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)

#include <CloudGemFramework/ServiceRequestJob.h>

#include "StdAfx.h"

namespace CloudGemMessageOfTheDay {
namespace ServiceAPI {
    
    extern const char* LmbrAWS_CodeGen_MessageList_UUID;
    
    extern const char* LmbrAWS_CodeGen_PutAdminMessagesReturnType_UUID;
    
    extern const char* LmbrAWS_CodeGen_Component_UUID;
    
    extern const char* LmbrAWS_CodeGen_ResponseHandler_UUID;
    
    extern const char* LmbrAWS_CodeGen_NotificationBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_RequestBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_DeleteAdminMessagesReturnType_UUID;
    
    extern const char* LmbrAWS_CodeGen_DetailedMessageList_UUID;
    
    extern const char* LmbrAWS_CodeGen_ServiceStatus_UUID;
    
    extern const char* LmbrAWS_CodeGen_DetailedMessageData_UUID;
    
    extern const char* LmbrAWS_CodeGen_MessageData_UUID;
    

    // redefs
    

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const int& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const AZStd::string& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const double& item);

    
    
    struct MessageData
    {

        AZ_TYPE_INFO(MessageData, LmbrAWS_CodeGen_MessageData_UUID)
        AZ_CLASS_ALLOCATOR(MessageData, AZ::SystemAllocator, 0)

        
        int priority;
        
        AZStd::string message;
        
        AZStd::string endTime;
        
        AZStd::string startTime;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const MessageData& item);
    
    
    
    struct PutAdminMessagesReturnType
    {

        AZ_TYPE_INFO(PutAdminMessagesReturnType, LmbrAWS_CodeGen_PutAdminMessagesReturnType_UUID)
        AZ_CLASS_ALLOCATOR(PutAdminMessagesReturnType, AZ::SystemAllocator, 0)

        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PutAdminMessagesReturnType& item);
    
    
    
    struct DeleteAdminMessagesReturnType
    {

        AZ_TYPE_INFO(DeleteAdminMessagesReturnType, LmbrAWS_CodeGen_DeleteAdminMessagesReturnType_UUID)
        AZ_CLASS_ALLOCATOR(DeleteAdminMessagesReturnType, AZ::SystemAllocator, 0)

        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const DeleteAdminMessagesReturnType& item);
    
    
    
    struct DetailedMessageData
    {

        AZ_TYPE_INFO(DetailedMessageData, LmbrAWS_CodeGen_DetailedMessageData_UUID)
        AZ_CLASS_ALLOCATOR(DetailedMessageData, AZ::SystemAllocator, 0)

        
        int priority;
        
        AZStd::string message;
        
        AZStd::string endTime;
        
        AZStd::string UniqueMsgID;
        
        AZStd::string startTime;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const DetailedMessageData& item);
    
    
    
    using DetailedMessageListPropertyList = AZStd::vector<DetailedMessageData>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const DetailedMessageListPropertyList& list);
    
    
    
    struct DetailedMessageList
    {

        AZ_TYPE_INFO(DetailedMessageList, LmbrAWS_CodeGen_DetailedMessageList_UUID)
        AZ_CLASS_ALLOCATOR(DetailedMessageList, AZ::SystemAllocator, 0)

        
        DetailedMessageListPropertyList list;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const DetailedMessageList& item);
    
    
    
    struct ServiceStatus
    {

        AZ_TYPE_INFO(ServiceStatus, LmbrAWS_CodeGen_ServiceStatus_UUID)
        AZ_CLASS_ALLOCATOR(ServiceStatus, AZ::SystemAllocator, 0)

        
        AZStd::string status;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const ServiceStatus& item);
    
    
    
    using MessageListPropertyList = AZStd::vector<MessageData>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const MessageListPropertyList& list);
    
    
    
    struct MessageList
    {

        AZ_TYPE_INFO(MessageList, LmbrAWS_CodeGen_MessageList_UUID)
        AZ_CLASS_ALLOCATOR(MessageList, AZ::SystemAllocator, 0)

        
        MessageListPropertyList list;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const MessageList& item);
    
    


    // Service RequestJobs
    CLOUD_GEM_SERVICE(CloudGemMessageOfTheDay);


    
    class PutAdminMessagesRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_PUT, "/admin/messages/{msg_id}");

        struct Parameters
        {
            
            AZStd::string msg_id;
            
            MessageData msg;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PutAdminMessagesReturnType result;
        

        Parameters parameters;
    };


    using PutAdminMessagesRequestJob = CloudGemFramework::ServiceRequestJob<PutAdminMessagesRequest>;
    
    class DeleteAdminMessagesRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_DELETE, "/admin/messages/{msg_id}");

        struct Parameters
        {
            
            AZStd::string msg_id;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        DeleteAdminMessagesReturnType result;
        

        Parameters parameters;
    };


    using DeleteAdminMessagesRequestJob = CloudGemFramework::ServiceRequestJob<DeleteAdminMessagesRequest>;
    
    class PostAdminMessagesRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_POST, "/admin/messages");

        struct Parameters
        {
            
            MessageData msg;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        DetailedMessageData result;
        

        Parameters parameters;
    };


    using PostAdminMessagesRequestJob = CloudGemFramework::ServiceRequestJob<PostAdminMessagesRequest>;
    
    class GetAdminMessagesRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_GET, "/admin/messages");

        struct Parameters
        {
            
            int index;
            
            int count;
            
            AZStd::string filter;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        DetailedMessageList result;
        

        Parameters parameters;
    };


    using GetAdminMessagesRequestJob = CloudGemFramework::ServiceRequestJob<GetAdminMessagesRequest>;
    
    class get_service_statusRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_GET, "/service/status");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        ServiceStatus result;
        

        Parameters parameters;
    };


    using get_service_statusRequestJob = CloudGemFramework::ServiceRequestJob<get_service_statusRequest>;
    
    class GetPlayerMessagesRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemMessageOfTheDay, HttpMethod::HTTP_GET, "/player/messages");

        struct Parameters
        {
            
            AZStd::string time;
            
            AZStd::string lang;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        MessageList result;
        

        Parameters parameters;
    };


    using GetPlayerMessagesRequestJob = CloudGemFramework::ServiceRequestJob<GetPlayerMessagesRequest>;
    


    // Notification bus for this component
    class CloudGemMessageOfTheDayNotifications
        : public AZ::ComponentBus
    {
    public:
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnPutAdminMessagesRequestSuccess(const PutAdminMessagesReturnType response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnPutAdminMessagesRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnDeleteAdminMessagesRequestSuccess(const DeleteAdminMessagesReturnType response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnDeleteAdminMessagesRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnPostAdminMessagesRequestSuccess(const DetailedMessageData response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnPostAdminMessagesRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetAdminMessagesRequestSuccess(const DetailedMessageList response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetAdminMessagesRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void Onget_service_statusRequestSuccess(const ServiceStatus response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void Onget_service_statusRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetPlayerMessagesRequestSuccess(const MessageList response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetPlayerMessagesRequestError(const CloudGemFramework::Error error);
        
    };

    using CloudGemMessageOfTheDayNotificationBus = AZ::EBus<CloudGemMessageOfTheDayNotifications>;

    class BehaviorCloudGemMessageOfTheDayNotificationBusHandler
        : public CloudGemMessageOfTheDayNotificationBus::Handler, public AZ::BehaviorEBusHandler
    {
    public:
        AZ_EBUS_BEHAVIOR_BINDER(BehaviorCloudGemMessageOfTheDayNotificationBusHandler, LmbrAWS_CodeGen_NotificationBus1_UUID, AZ::SystemAllocator
        
        , OnPutAdminMessagesRequestSuccess
        , OnPutAdminMessagesRequestError
        
        , OnDeleteAdminMessagesRequestSuccess
        , OnDeleteAdminMessagesRequestError
        
        , OnPostAdminMessagesRequestSuccess
        , OnPostAdminMessagesRequestError
        
        , OnGetAdminMessagesRequestSuccess
        , OnGetAdminMessagesRequestError
        
        , Onget_service_statusRequestSuccess
        , Onget_service_statusRequestError
        
        , OnGetPlayerMessagesRequestSuccess
        , OnGetPlayerMessagesRequestError
        
        );
        
        
        void OnPutAdminMessagesRequestSuccess(const PutAdminMessagesReturnType response) override;
        
        void OnPutAdminMessagesRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnDeleteAdminMessagesRequestSuccess(const DeleteAdminMessagesReturnType response) override;
        
        void OnDeleteAdminMessagesRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnPostAdminMessagesRequestSuccess(const DetailedMessageData response) override;
        
        void OnPostAdminMessagesRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetAdminMessagesRequestSuccess(const DetailedMessageList response) override;
        
        void OnGetAdminMessagesRequestError(const CloudGemFramework::Error error) override;
        
        
        void Onget_service_statusRequestSuccess(const ServiceStatus response) override;
        
        void Onget_service_statusRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetPlayerMessagesRequestSuccess(const MessageList response) override;
        
        void OnGetPlayerMessagesRequestError(const CloudGemFramework::Error error) override;
        
    };
    class CloudGemMessageOfTheDayResponseHandler;

    // Request bus for this component
    class CloudGemMessageOfTheDayRequests
        : public AZ::ComponentBus
    {
    public:
        virtual ~CloudGemMessageOfTheDayRequests() {}
        
        
        virtual void PutAdminMessages(const AZStd::string& msg_id, const MessageData& msg, CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
        
        virtual void DeleteAdminMessages(const AZStd::string& msg_id, CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
        
        virtual void PostAdminMessages(const MessageData& msg, CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
        
        virtual void GetAdminMessages(const int& index, const int& count, const AZStd::string& filter, CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
        
        virtual void get_service_status(CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
        
        virtual void GetPlayerMessages(const AZStd::string& time, const AZStd::string& lang, CloudGemMessageOfTheDayResponseHandler* responseHandler);
        
        
    };

    using CloudGemMessageOfTheDayRequestBus = AZ::EBus<CloudGemMessageOfTheDayRequests>;

    // This class is used as a parameter for all requests and throws the response on the CloudGemMessageOfTheDayNotificationBus
    // Inherit from this to define custom behavior.
    class CloudGemMessageOfTheDayResponseHandler
    {
    public:
        AZ_TYPE_INFO(CloudGemMessageOfTheDayResponseHandler, LmbrAWS_CodeGen_ResponseHandler_UUID)
        AZ_CLASS_ALLOCATOR(CloudGemMessageOfTheDayResponseHandler, AZ::SystemAllocator, 0)

        virtual ~CloudGemMessageOfTheDayResponseHandler() {}
        
        virtual void HandlePutAdminMessagesSuccess(PutAdminMessagesRequestJob* job, AZ::EntityId entityId);
        virtual void HandlePutAdminMessagesError(PutAdminMessagesRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleDeleteAdminMessagesSuccess(DeleteAdminMessagesRequestJob* job, AZ::EntityId entityId);
        virtual void HandleDeleteAdminMessagesError(DeleteAdminMessagesRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandlePostAdminMessagesSuccess(PostAdminMessagesRequestJob* job, AZ::EntityId entityId);
        virtual void HandlePostAdminMessagesError(PostAdminMessagesRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetAdminMessagesSuccess(GetAdminMessagesRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetAdminMessagesError(GetAdminMessagesRequestJob* job, AZ::EntityId entityId);
        
        virtual void Handleget_service_statusSuccess(get_service_statusRequestJob* job, AZ::EntityId entityId);
        virtual void Handleget_service_statusError(get_service_statusRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetPlayerMessagesSuccess(GetPlayerMessagesRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetPlayerMessagesError(GetPlayerMessagesRequestJob* job, AZ::EntityId entityId);
        
    };

    class CloudGemMessageOfTheDayClientComponent
        : public AZ::Component
        , public CloudGemMessageOfTheDayRequestBus::Handler
    {
    public:
        AZ_COMPONENT(CloudGemMessageOfTheDayClientComponent, LmbrAWS_CodeGen_Component_UUID);
        virtual ~CloudGemMessageOfTheDayClientComponent() = default;

        AZStd::shared_ptr<CloudGemMessageOfTheDayResponseHandler> m_defaultResponseHandler;

        void Init() override;

        void Activate() override;

        void Deactivate() override;

        static void Reflect(AZ::ReflectContext* reflection)
        {
            
            
            MessageData::Reflect(reflection);
            
            
            
            PutAdminMessagesReturnType::Reflect(reflection);
            
            
            
            DeleteAdminMessagesReturnType::Reflect(reflection);
            
            
            
            DetailedMessageData::Reflect(reflection);
            
            
            
            
            
            DetailedMessageList::Reflect(reflection);
            
            
            
            ServiceStatus::Reflect(reflection);
            
            
            
            
            
            MessageList::Reflect(reflection);
            
            

            AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection);
            if (serializeContext)
            {
                // we must include any fields we want to expose to the editor or lua in the serialize context
                serializeContext->Class<CloudGemMessageOfTheDayClientComponent>()
                    ->Version(1);

                AZ::EditContext* editContext = serializeContext->GetEditContext();
                if (editContext)
                {
                    editContext->Class<CloudGemMessageOfTheDayClientComponent>("CloudGemMessageOfTheDayClientComponent", "CloudGemMessageOfTheDay Component")
                        ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                            ->Attribute(AZ::Edit::Attributes::Category, "Cloud Canvas Gems")
                            ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"));
                }
            }

            AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(reflection);
            if (behaviorContext)
            {
                behaviorContext->EBus<CloudGemMessageOfTheDayRequestBus>("CloudGemMessageOfTheDayRequestBus")
                    // one of these for each function
                    
                    ->Event("PutAdminMessages", &CloudGemMessageOfTheDayRequestBus::Events::PutAdminMessages)
                    
                    ->Event("DeleteAdminMessages", &CloudGemMessageOfTheDayRequestBus::Events::DeleteAdminMessages)
                    
                    ->Event("PostAdminMessages", &CloudGemMessageOfTheDayRequestBus::Events::PostAdminMessages)
                    
                    ->Event("GetAdminMessages", &CloudGemMessageOfTheDayRequestBus::Events::GetAdminMessages)
                    
                    ->Event("get_service_status", &CloudGemMessageOfTheDayRequestBus::Events::get_service_status)
                    
                    ->Event("GetPlayerMessages", &CloudGemMessageOfTheDayRequestBus::Events::GetPlayerMessages)
                    
                    ;
                behaviorContext->EBus<CloudGemMessageOfTheDayNotificationBus>("CloudGemMessageOfTheDayNotificationBus")
                    ->Handler<BehaviorCloudGemMessageOfTheDayNotificationBusHandler>()
                ;
            }
        }

        // Functions from the swagger definitions
        
        
        void PutAdminMessages(const AZStd::string& msg_id, const MessageData& msg, CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
        
        void DeleteAdminMessages(const AZStd::string& msg_id, CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
        
        void PostAdminMessages(const MessageData& msg, CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
        
        void GetAdminMessages(const int& index, const int& count, const AZStd::string& filter, CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
        
        void get_service_status(CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
        
        void GetPlayerMessages(const AZStd::string& time, const AZStd::string& lang, CloudGemMessageOfTheDayResponseHandler* responseHandler) override;
        
        
    };
} // ServiceAPI
} // CloudGemMessageOfTheDay