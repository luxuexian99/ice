# **********************************************************************
#
# Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

$(test)_client_sources = Client.cpp BackendI.cpp Backend.ice
$(test)_client_dependencies = Glacier2

$(test)_server_sources = Server.cpp BackendI.cpp Backend.ice

tests += $(test)
