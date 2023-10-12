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

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_VESTING = "Vesting";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_SUDO = "Sudo";
static const char* STR_MO_CONTRACTS = "Contracts";
static const char* STR_MO_NOMINATIONPOOLS = "Nominationpools";

// Methods names
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_SET_BALANCE = "Set balance";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_KICK = "Kick";
static const char* STR_ME_SET_STAKING_CONFIGS = "Set staking configs";
static const char* STR_ME_CHILL_OTHER = "Chill other";
static const char* STR_ME_FORCE_APPLY_MIN_COMMISSION = "Force apply min commission";
static const char* STR_ME_SET_MIN_COMMISSION = "Set min commission";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_VEST = "Vest";
static const char* STR_ME_VEST_OTHER = "Vest other";
static const char* STR_ME_VESTED_TRANSFER = "Vested transfer";
static const char* STR_ME_FORCE_VESTED_TRANSFER = "Force vested transfer";
static const char* STR_ME_MERGE_SCHEDULES = "Merge schedules";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_DISPATCH_AS = "Dispatch as";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_WITH_WEIGHT = "With weight";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char* STR_ME_SUDO = "Sudo";
static const char* STR_ME_SUDO_UNCHECKED_WEIGHT = "Sudo unchecked weight";
static const char* STR_ME_SET_KEY = "Set key";
static const char* STR_ME_SUDO_AS = "Sudo as";
static const char* STR_ME_CALL_OLD_WEIGHT = "Call old weight";
static const char* STR_ME_INSTANTIATE_WITH_CODE_OLD_WEIGHT = "Instantiate with code old weight";
static const char* STR_ME_INSTANTIATE_OLD_WEIGHT = "Instantiate old weight";
static const char* STR_ME_UPLOAD_CODE = "Upload code";
static const char* STR_ME_REMOVE_CODE = "Remove code";
static const char* STR_ME_CALL = "Call";
static const char* STR_ME_INSTANTIATE_WITH_CODE = "Instantiate with code";
static const char* STR_ME_INSTANTIATE = "Instantiate";
static const char* STR_ME_JOIN = "Join";
static const char* STR_ME_CLAIM_PAYOUT = "Claim payout";
static const char* STR_ME_POOL_WITHDRAW_UNBONDED = "Pool withdraw unbonded";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_CREATE_WITH_POOL_ID = "Create with pool id";
static const char* STR_ME_SET_STATE = "Set state";
static const char* STR_ME_SET_METADATA = "Set metadata";
static const char* STR_ME_SET_CONFIGS = "Set configs";
static const char* STR_ME_UPDATE_ROLES = "Update roles";

// Items names
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_min_nominator_bond = "Min nominator bond";
static const char* STR_IT_min_validator_bond = "Min validator bond";
static const char* STR_IT_max_nominator_count = "Max nominator count";
static const char* STR_IT_max_validator_count = "Max validator count";
static const char* STR_IT_chill_threshold = "Chill threshold";
static const char* STR_IT_min_commission = "Min commission";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_target = "Target";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_schedule1_index = "Schedule1 index";
static const char* STR_IT_schedule2_index = "Schedule2 index";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_index = "Index";
static const char* STR_IT_call = "Call";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_weight = "Weight";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_gas_limit = "Gas limit";
static const char* STR_IT_storage_deposit_limit = "Storage deposit limit";
static const char* STR_IT_data = "Data";
static const char* STR_IT_salt = "Salt";
static const char* STR_IT_code_hash = "Code hash";
static const char* STR_IT_determinism = "Determinism";
static const char* STR_IT_pool_id = "Pool id";
static const char* STR_IT_extra = "Extra";
static const char* STR_IT_member_account = "Member account";
static const char* STR_IT_unbonding_points = "Unbonding points";
static const char* STR_IT_root = "Root";
static const char* STR_IT_nominator = "Nominator";
static const char* STR_IT_state_toggler = "State toggler";
static const char* STR_IT_validators = "Validators";
static const char* STR_IT_state = "State";
static const char* STR_IT_metadata = "Metadata";
static const char* STR_IT_min_join_bond = "Min join bond";
static const char* STR_IT_min_create_bond = "Min create bond";
static const char* STR_IT_max_pools = "Max pools";
static const char* STR_IT_max_members = "Max members";
static const char* STR_IT_max_members_per_pool = "Max members per pool";
static const char* STR_IT_new_root = "New root";
static const char* STR_IT_new_nominator = "New nominator";
static const char* STR_IT_new_state_toggler = "New state toggler";

#ifdef __cplusplus
}
#endif
