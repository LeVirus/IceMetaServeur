// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.1
//
// <auto-generated>
//
// Generated from file `Logger.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Logger_h__
#define __Ice_Logger_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_API
#   ifdef ICE_API_EXPORTS
#       define ICE_API ICE_DECLSPEC_EXPORT
#   elif defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace Ice
{

class Logger;
bool operator==(const Logger&, const Logger&);
bool operator<(const Logger&, const Logger&);
ICE_API ::Ice::LocalObject* upCast(::Ice::Logger*);
typedef ::IceInternal::Handle< ::Ice::Logger> LoggerPtr;

}

namespace Ice
{

class ICE_API Logger : virtual public ::Ice::LocalObject
{
public:

    typedef LoggerPtr PointerType;

    virtual void print(const ::std::string&) = 0;

    virtual void trace(const ::std::string&, const ::std::string&) = 0;

    virtual void warning(const ::std::string&) = 0;

    virtual void error(const ::std::string&) = 0;

    virtual ::std::string getPrefix() = 0;

    virtual ::Ice::LoggerPtr cloneWithPrefix(const ::std::string&) = 0;
};

inline bool operator==(const Logger& l, const Logger& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) == static_cast<const ::Ice::LocalObject&>(r);
}

inline bool operator<(const Logger& l, const Logger& r)
{
    return static_cast<const ::Ice::LocalObject&>(l) < static_cast<const ::Ice::LocalObject&>(r);
}

}

#include <IceUtil/PopDisableWarnings.h>
#endif
