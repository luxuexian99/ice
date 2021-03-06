// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#include <Ice/Ice.h>
#include <TestAMDI.h>
#include <TestCommon.h>

using namespace Test;
using namespace std;

bool
endsWith(const string& s, const string& findme)
{
    if(s.length() > findme.length())
    {
        return 0 == s.compare(s.length() - findme.length(), findme.length(), findme);
    }
    return false;
}

ThrowerI::ThrowerI()
{
}

#ifdef ICE_CPP11_MAPPING
void
ThrowerI::shutdown_async(function<void ()> response,
                         function<void (exception_ptr)>,
                         const Ice::Current& current)
{
    current.adapter->getCommunicator()->shutdown();
    response();
}

void
ThrowerI::supportsUndeclaredExceptions_async(function<void (bool)> response,
                                             function<void (exception_ptr)>,
                                             const Ice::Current&)
{
    response(true);
}

void
ThrowerI::supportsAssertException_async(function<void (bool)> response,
                                        function<void (exception_ptr)>,
                                        const Ice::Current&)
{
    response(false);
}

void
ThrowerI::throwAasA_async(int a,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        A ex;
        ex.aMem = a;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwAorDasAorD_async(int a,
                                function<void ()>,
                                function<void (exception_ptr)> exception,
                                const Ice::Current&)
{
    try
    {
        if(a > 0)
        {
            A ex;
            ex.aMem = a;
            throw ex;
        }
        else
        {
            D ex;
            ex.dMem = a;
            throw ex;
        }
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwBasA_async(int a, int b,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        B ex;
        ex.aMem = a;
        ex.bMem = b;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasA_async(int a, int b, int c,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwBasB_async(int a, int b,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        B ex;
        ex.aMem = a;
        ex.bMem = b;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasB_async(int a, int b, int c,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasC_async(int a, int b, int c,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwModA_async(int a, int a2,
                          function<void ()>,
                          function<void (exception_ptr)> exception,
                          const Ice::Current&)
{
    Mod::A ex;
    ex.aMem = a;
    ex.a2Mem = a2;
    throw ex;
}

void
ThrowerI::throwUndeclaredA_async(int a,
                                 function<void ()>,
                                 function<void (exception_ptr)> exception,
                                  const Ice::Current&)
{
    try
    {
        A ex;
        ex.aMem = a;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwUndeclaredB_async(int a, int b,
                                 function<void ()>,
                                 function<void (exception_ptr)>,
                                 const Ice::Current&)
{
    B ex;
    ex.aMem = a;
    ex.bMem = b;
    throw ex;
}

void
ThrowerI::throwUndeclaredC_async(int a, int b, int c,
                                 function<void ()>,
                                 function<void (exception_ptr)> exception,
                                 const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwLocalException_async(function<void ()>,
                                    function<void (exception_ptr)> exception,
                                    const Ice::Current&)
{
    try
    {
        throw Ice::TimeoutException(__FILE__, __LINE__);
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwNonIceException_async(function<void ()>,
                                     function<void (exception_ptr)> exception,
                                     const Ice::Current&)
{
    try
    {
        throw int(12345);
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwAssertException_async(function<void ()>,
                                     function<void (exception_ptr)>,
                                     const Ice::Current&)
{
    assert(false); // No supported in C++
}

void
ThrowerI::throwMemoryLimitException_async(ICE_IN(Ice::ByteSeq),
                                          function<void (const Ice::ByteSeq&)> response,
                                          function<void (exception_ptr)>,
                                          const Ice::Current&)
{
    response(Ice::ByteSeq(1024 * 20)); // 20 KB.
}

void
ThrowerI::throwLocalExceptionIdempotent_async(function<void ()>,
                                              function<void (exception_ptr)> exception,
                                              const Ice::Current&)
{
    try
    {
        throw Ice::TimeoutException(__FILE__, __LINE__);
    }
    catch(...)
    {
        exception(current_exception());
    }
    
}

void
ThrowerI::throwAfterResponse_async(function<void ()> response,
                                   function<void (exception_ptr)>,
                                   const Ice::Current&)
{
    response();

    throw std::string();
}

void
ThrowerI::throwAfterException_async(function<void ()>,
                                    function<void (exception_ptr)> exception,
                                    const Ice::Current&)
{
    try
    {
        throw A(12345);
    }
    catch(...)
    {
        exception(current_exception());
    }
    throw std::string();
}

void
ThrowerI::throwE_async(function<void ()>,
                       function<void (exception_ptr)> exception,
                       const Ice::Current&)
{
    try
    {
        throw E("E");
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwF_async(function<void ()>,
                       function<void (exception_ptr)> exception,
                       const Ice::Current&)
{
    try
    {
        throw F("F");
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwG_async(function<void ()>,
                       function<void (exception_ptr)> exception,
                       const Ice::Current&)
{
    try
    {
        throw G(__FILE__, __LINE__, "G");
    }
    catch(const G& ex)
    {
        ostringstream os;
        ex.ice_print(os);
        test(endsWith(os.str(), "Test::G"));
        test(ex.data == "G");
        exception(current_exception());
    }
}

void
ThrowerI::throwH_async(function<void ()>,
                       function<void (exception_ptr)> exception,
                       const Ice::Current&)
{
    try
    {
        throw H(__FILE__, __LINE__, "H");
    }
    catch(const H& ex)
    {
        ostringstream os;
        ex.ice_print(os);
        test(endsWith(os.str(), "Test::H data:'H'"));
        test(ex.data == "H");
        exception(current_exception());
    }
}
#else

void
ThrowerI::shutdown_async(const AMD_Thrower_shutdownPtr& cb,
                         const Ice::Current& current)
{
    current.adapter->getCommunicator()->shutdown();
    cb->ice_response();
}

void
ThrowerI::supportsUndeclaredExceptions_async(const AMD_Thrower_supportsUndeclaredExceptionsPtr& cb,
                                             const Ice::Current&)
{
    cb->ice_response(true);
}

void
ThrowerI::supportsAssertException_async(const AMD_Thrower_supportsAssertExceptionPtr& cb,
                                        const Ice::Current&)
{
    cb->ice_response(false);
}

void
ThrowerI::throwAasA_async(const AMD_Thrower_throwAasAPtr& cb,
                          Ice::Int a, const Ice::Current&)
{
    A ex;
    ex.aMem = a;
    cb->ice_exception(ex);
}

void
ThrowerI::throwAorDasAorD_async(const AMD_Thrower_throwAorDasAorDPtr& cb,
                                Ice::Int a, const Ice::Current&)
{
    if(a > 0)
    {
        A ex;
        ex.aMem = a;
        cb->ice_exception(ex);
    }
    else
    {
        D ex;
        ex.dMem = a;
        cb->ice_exception(ex);
    }
}

void
ThrowerI::throwBasA_async(const AMD_Thrower_throwBasAPtr& /*cb*/,
                          Ice::Int a, Ice::Int b, const Ice::Current&)
{
    B ex;
    ex.aMem = a;
    ex.bMem = b;
    throw ex;
    //cb->ice_exception(ex);
}

void
ThrowerI::throwCasA_async(const AMD_Thrower_throwCasAPtr& cb,
                          Ice::Int a, Ice::Int b, Ice::Int c, const Ice::Current&)
{
    C ex;
    ex.aMem = a;
    ex.bMem = b;
    ex.cMem = c;
    cb->ice_exception(ex);
}

void
ThrowerI::throwBasB_async(const AMD_Thrower_throwBasBPtr& /*cb*/,
                          Ice::Int a, Ice::Int b, const Ice::Current&)
{
    B ex;
    ex.aMem = a;
    ex.bMem = b;
    throw ex;
    //cb->ice_exception(ex);
}

void
ThrowerI::throwCasB_async(const AMD_Thrower_throwCasBPtr& cb,
                          Ice::Int a, Ice::Int b, Ice::Int c, const Ice::Current&)
{
    C ex;
    ex.aMem = a;
    ex.bMem = b;
    ex.cMem = c;
    cb->ice_exception(ex);
}

void
ThrowerI::throwCasC_async(const AMD_Thrower_throwCasCPtr& cb,
                          Ice::Int a, Ice::Int b, Ice::Int c, const Ice::Current&)
{
    C ex;
    ex.aMem = a;
    ex.bMem = b;
    ex.cMem = c;
    cb->ice_exception(ex);
}

void
ThrowerI::throwModA_async(const AMD_Thrower_throwModAPtr& /*cb*/,
                          Ice::Int a, Ice::Int a2, const Ice::Current&)
{
    Mod::A ex;
    ex.aMem = a;
    ex.a2Mem = a2;
    throw ex;
}


void
ThrowerI::throwUndeclaredA_async(const AMD_Thrower_throwUndeclaredAPtr& cb,
                                 Ice::Int a, const Ice::Current&)
{
    A ex;
    ex.aMem = a;
    cb->ice_exception(ex);
}

void
ThrowerI::throwUndeclaredB_async(const AMD_Thrower_throwUndeclaredBPtr& /*cb*/,
                                 Ice::Int a, Ice::Int b, const Ice::Current&)
{
    B ex;
    ex.aMem = a;
    ex.bMem = b;
    throw ex;
    //cb->ice_exception(ex);
}

void
ThrowerI::throwUndeclaredC_async(const AMD_Thrower_throwUndeclaredCPtr& cb,
                                 Ice::Int a, Ice::Int b, Ice::Int c, const Ice::Current&)
{
    C ex;
    ex.aMem = a;
    ex.bMem = b;
    ex.cMem = c;
    cb->ice_exception(ex);
}

void
ThrowerI::throwLocalException_async(const AMD_Thrower_throwLocalExceptionPtr& cb,
                                    const Ice::Current&)
{
    cb->ice_exception(Ice::TimeoutException(__FILE__, __LINE__));
}

void
ThrowerI::throwNonIceException_async(const AMD_Thrower_throwNonIceExceptionPtr&,
                                     const Ice::Current&)
{
    throw int(12345);
}

void
ThrowerI::throwAssertException_async(const AMD_Thrower_throwAssertExceptionPtr&,
                                     const Ice::Current&)
{
    assert(false); // Not supported in C++.
}

void
ThrowerI::throwMemoryLimitException_async(const AMD_Thrower_throwMemoryLimitExceptionPtr& cb,
                                          const Ice::ByteSeq&, const Ice::Current&)
{
    cb->ice_response(Ice::ByteSeq(1024 * 20)); // 20 KB.
}


void
ThrowerI::throwLocalExceptionIdempotent_async(const AMD_Thrower_throwLocalExceptionIdempotentPtr& cb,
                                              const Ice::Current&)
{
    cb->ice_exception(Ice::TimeoutException(__FILE__, __LINE__));
}

void
ThrowerI::throwAfterResponse_async(const AMD_Thrower_throwAfterResponsePtr& cb, const Ice::Current&)
{
    cb->ice_response();

    throw std::string();
}

void
ThrowerI::throwAfterException_async(const AMD_Thrower_throwAfterExceptionPtr& cb, const Ice::Current&)
{
    cb->ice_exception(A(12345));

    throw std::string();
}

void
ThrowerI::throwE_async(const Test::AMD_Thrower_throwEPtr& cb, const Ice::Current&)
{
    cb->ice_exception(E("E"));
}

void
ThrowerI::throwF_async(const Test::AMD_Thrower_throwFPtr& cb, const Ice::Current&)
{
    cb->ice_exception(F("F"));
}

void
ThrowerI::throwG_async(const Test::AMD_Thrower_throwGPtr& cb, const Ice::Current&)
{
    try
    {
        throw G(__FILE__, __LINE__, "G");
    }
    catch(const G& ex)
    {
        ostringstream os;
        ex.ice_print(os);
        test(endsWith(os.str(), "Test::G"));
        test(ex.data == "G");
        cb->ice_exception(ex);
    }
}

void
ThrowerI::throwH_async(const Test::AMD_Thrower_throwHPtr& cb, const Ice::Current&)
{
    try
    {
        throw H(__FILE__, __LINE__, "H");
    }
    catch(const H& ex)
    {
        ostringstream os;
        ex.ice_print(os);
        test(endsWith(os.str(), "Test::H data:'H'"));
        test(ex.data == "H");
        cb->ice_exception(ex);
    }
}
#endif
