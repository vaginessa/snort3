/****************************************************************************
 *
** Copyright (C) 2014 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2003-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 ****************************************************************************/

//
//  @author     Tom Peters <thopeter@cisco.com>
//
//  @brief      NHTTP Stream Splitter class
//

#ifndef NHTTP_STREAM_SPLITTER_H
#define NHTTP_STREAM_SPLITTER_H

#include "stream/stream_splitter.h"
#include "nhttp_flow_data.h"

class NHttpStreamSplitter : public StreamSplitter {
public:
    NHttpStreamSplitter(bool isClientToServer) : StreamSplitter(isClientToServer) {};
    PAF_Status scan(Flow* flow, const uint8_t* data, uint32_t length, uint32_t flags, uint32_t* flushOffset);
    bool is_paf() { return true; };
    uint32_t max() { return pafMax; };
private:
    void prepareFlush(NHttpFlowData* sessionData, uint32_t* flushOffset, NHttpEnums::SourceId sourceId, NHttpEnums::SectionType sectionType, bool tcpClose,
          uint64_t infractions, uint32_t numOctets);
    void createEvent(NHttpEnums::EventSid sid);

    uint64_t eventsGenerated = 0;
    int64_t octetsSeen;
    int numCrlf;
    uint32_t pafMax = 63780;
};

#endif














