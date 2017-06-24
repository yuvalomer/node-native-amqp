#ifndef Message_H
#define Message_H

#include <string>
#include <nan.h>
#include <SimpleAmqpClient/SimpleAmqpClient.h>


class Message : public Nan::ObjectWrap {
    public:
        static Nan::Persistent<v8::Function> constructor;
        static void Init();
        explicit Message(AmqpClient::Channel::ptr_t &channel, const AmqpClient::Envelope::ptr_t &msg_envelope);
        explicit Message();
        static void JsValue(const Nan::FunctionCallbackInfo<v8::Value>& info);
        v8::Local<v8::Object> V8Instance();
        static void JsAck(const Nan::FunctionCallbackInfo<v8::Value>& info);
        static void JsReject(const Nan::FunctionCallbackInfo<v8::Value>& info);
        void Ack(void);
        bool Valid(void);
        void Reject(bool requeue);
        std::string MessageBody(void);
        virtual ~Message();

    protected:

    private:
        AmqpClient::Channel::ptr_t m_channel;
        AmqpClient::Envelope::ptr_t m_envelope;
        static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
        static void New(const Nan::FunctionCallbackInfo<v8::Value>& info, AmqpClient::Channel::ptr_t channel, const AmqpClient::Envelope::ptr_t &msg_envelope);
        static v8::Local<v8::Object> NewInstance(v8::Local<v8::Value> arg);
};

#endif // Message_H
