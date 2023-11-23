/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

#include "stdbool.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop
#endif

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint8_t pd_u8_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;
typedef uint32_t pd_BlockNumber_t;

#define CHECK_ERROR(FUNC_CALL)          \
    {                                   \
        parser_error_t err = FUNC_CALL; \
        if (err != parser_ok)           \
            return err;                 \
    }

typedef struct {
    uint8_t moduleIdx;
    uint8_t idx;
} pd_CallIndex_t;

typedef enum {
    eEraImmortal = 0,
    eEraMortal = 1
} pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
    pd_ExtrinsicEra_e type;
    uint64_t period;
    uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
    const uint8_t* ptr;
    uint8_t len;
} compactInt_t;

typedef struct {
    uint32_t _lenBuffer;
    const uint8_t* _ptr; // Pointer to actual
    const uint8_t* _nextPtr; // Pointer to next Call
    uint8_t slotIdx; // Count of nested calls
    bool isTail;
} pd_NestCallIdx_t;

////////////////////////
// Common types
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef compactInt_t pd_CompactAssignments_t;
typedef compactInt_t pd_CompactBountyIndex_t;
typedef compactInt_t pd_CompactEraIndex_t;
typedef compactInt_t pd_CompactMemberCount_t;
typedef compactInt_t pd_CompactMoment_t;
typedef compactInt_t pd_CompactPropIndex_t;
typedef compactInt_t pd_CompactProposalIndex_t;
typedef compactInt_t pd_CompactReferendumIndex_t;
typedef compactInt_t pd_CompactRegistrarIndex_t;
typedef compactInt_t pd_CompactWeight_t;

typedef enum {
    eAddressIndex = 0,
    eAddressId = 1
} pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t* idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Balance_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Bytes_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_t;

typedef struct {
    pd_Balance_t value;
} pd_BalanceOf_t;

typedef struct {
    pd_CallIndex_t callIndex;
    const uint32_t* _txVerPtr;
    pd_NestCallIdx_t nestCallIdx;
} pd_Call_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalanceOf_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

typedef struct {
    uint8_t value;
} pd_Percent_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t _signed;
} pd_SystemOrigin_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_t;

typedef struct {
    pd_Perbill_t perbill;
    pd_AccountId_t id;
} pd_TuplePerbillAccountId_t;

typedef struct {
    uint8_t value;
    pd_Balance_t freeBalance;
} pd_BondExtraBalanceOfT_t;

typedef struct {
    uint8_t value;
    pd_SystemOrigin_t system;
} pd_BoxPalletsOrigin_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_t;

typedef struct {
    pd_Perbill_t maxIncrease;
    uint32_t minDelay;
} pd_CommissionChangeRateBlockNumber_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t set;
} pd_ConfigOpAccountId_t;

typedef struct {
    uint8_t value;
    pd_Balance_t set;
} pd_ConfigOpBalanceOfT_t;

typedef struct {
    uint8_t value;
    pd_Perbill_t set;
} pd_ConfigOpPerbill_t;

typedef struct {
    uint8_t value;
    pd_Percent_t set;
} pd_ConfigOpPercent_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    uint8_t some;
    pd_TuplePerbillAccountId_t contained;
} pd_OptionTuplePerbillAccountId_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t accountId;
} pd_RewardDestination_t;

typedef struct {
    pd_CompactPerBill_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountIdLookupOfT_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
    uint32_t callTxVersion;
} pd_VecCall_t;

typedef struct {
    pd_BalanceOf_t locked;
    pd_BalanceOf_t per_block;
    pd_BlockNumber_t starting_block;
} pd_VestingInfo_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    uint8_t value;
} pd_ClaimPermission_t;

typedef struct {
    uint8_t value;
    uint32_t set;
} pd_ConfigOpu32_t;

typedef struct {
    uint8_t value;
} pd_Determinism_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    const uint8_t* _ptr;
} pd_H256_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_t;

typedef struct {
    uint8_t some;
    pd_CompactBalanceOf_t contained;
} pd_OptionCompactBalanceOf_t;

typedef struct {
    uint32_t value;
} pd_PoolId_t;

typedef struct {
    uint8_t value;
} pd_PoolState_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu8_t;

#ifdef __cplusplus
}
#endif
