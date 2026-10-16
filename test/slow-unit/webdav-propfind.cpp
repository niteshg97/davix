/*
 * This File is part of Davix, The IO library for HTTP based protocols
 * Copyright (C) CERN 2026
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <gtest/gtest.h>
#include <davix.hpp>

#include "../drunk-server/DrunkServer.hpp"
#include "../drunk-server/Interactors.hpp"
#include "../drunk-server/LineReader.hpp"

#include <cstdlib>
#include <string>

using namespace Davix;

namespace {

const char propfind_response[] =
    "<?xml version=\"1.0\"?>"
    "<D:multistatus xmlns:D=\"DAV:\">"
    "<D:response><D:href>/</D:href><D:propstat><D:prop>"
    "<D:displayname>root</D:displayname>"
    "<D:getcontentlength>0</D:getcontentlength>"
    "<D:resourcetype><D:collection/></D:resourcetype>"
    "</D:prop><D:status>HTTP/1.1 200 OK</D:status></D:propstat></D:response>"
    "<D:response><D:href>/child</D:href><D:propstat><D:prop>"
    "<D:displayname>child</D:displayname>"
    "<D:getcontentlength>4</D:getcontentlength>"
    "<D:resourcetype/>"
    "</D:prop><D:status>HTTP/1.1 200 OK</D:status></D:propstat></D:response>"
    "</D:multistatus>";

class PropfindInteractor
