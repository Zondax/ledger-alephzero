/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V8.h"
#include "substrate_types_V8.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V8(parser_context_t* c, pd_AccountId_V8_t* v);
parser_error_t _readCompactAccountIndex_V8(parser_context_t* c, pd_CompactAccountIndex_V8_t* v);
parser_error_t _readKeys_V8(parser_context_t* c, pd_Keys_V8_t* v);
parser_error_t _readLookupasStaticLookupSource_V8(parser_context_t* c, pd_LookupasStaticLookupSource_V8_t* v);
parser_error_t _readOpaqueCall_V8(parser_context_t* c, pd_OpaqueCall_V8_t* v);
parser_error_t _readOptionTimepoint_V8(parser_context_t* c, pd_OptionTimepoint_V8_t* v);
parser_error_t _readPerbill_V8(parser_context_t* c, pd_Perbill_V8_t* v);
parser_error_t _readTimepoint_V8(parser_context_t* c, pd_Timepoint_V8_t* v);
parser_error_t _readVecAccountId_V8(parser_context_t* c, pd_VecAccountId_V8_t* v);
parser_error_t _readVestingInfo_V8(parser_context_t* c, pd_VestingInfo_V8_t* v);
parser_error_t _readWeight_V8(parser_context_t* c, pd_Weight_V8_t* v);

// toString functions
parser_error_t _toStringAccountId_V8(
    const pd_AccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V8(
    const pd_CompactAccountIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V8(
    const pd_Keys_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V8(
    const pd_LookupasStaticLookupSource_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V8(
    const pd_OpaqueCall_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V8(
    const pd_OptionTimepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V8(
    const pd_Perbill_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V8(
    const pd_Timepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V8(
    const pd_VecAccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V8(
    const pd_VestingInfo_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V8(
    const pd_Weight_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
