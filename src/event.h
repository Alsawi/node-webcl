// Copyright (c) 2011-2012, Motorola Mobility, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of the Motorola Mobility, Inc. nor the names of its
//    contributors may be used to endorse or promote products derived from this
//    software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef EVENT_H_
#define EVENT_H_

#include "common.h"

namespace webcl {

class Event : public WebCLObject
{

public:
  void Destructor();

  static void Init(v8::Handle<v8::Object> target);

  static Event *New(cl_event ew);

  static JS_METHOD(New);

  static JS_METHOD(getInfo);
  static JS_METHOD(getProfilingInfo);
  static JS_METHOD(setUserEventStatus);
  static JS_METHOD(setCallback);

  cl_event getEvent() const { return event; };
  void setEvent(cl_event e);
  bool isEvent() const { return true; }

  static v8::Handle<v8::Value> GetStatus(v8::Local<v8::String> property, const v8::AccessorInfo& info);
  static v8::Handle<v8::Value> GetBuffer(v8::Local<v8::String> property, const v8::AccessorInfo& info);

private:
  Event(v8::Handle<v8::Object> wrapper);

  static void callback (cl_event event, cl_int event_command_exec_status, void *user_data);
  static void After_cb(uv_async_t* handle, int status);

  static v8::Persistent<v8::FunctionTemplate> constructor_template;

  cl_event event;

  void *buffer;
  cl_int status;
};

} // namespace

#endif
