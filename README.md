# Ledger Aleph Zero App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-alephzero/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-alephzero/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Aleph Zero app (https://alephzero.org/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Aleph Zero 16.65.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |

## Scheduler

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                  |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| Schedule             |        |           |                  |         | `BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                   |
| Cancel               |        |           |                  |         | `BlockNumber`when<br/>`u32`index<br/>                                                                                                      |
| Schedule named       |        |           |                  |         | `TaskName`id<br/>`BlockNumber`when<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>  |
| Cancel named         |        |           |                  |         | `TaskName`id<br/>                                                                                                                          |
| Schedule after       |        |           |                  |         | `BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/>                  |
| Schedule named after |        |           |                  |         | `TaskName`id<br/>`BlockNumber`after<br/>`OptionschedulePeriodBlockNumber`maybe_periodic<br/>`schedulePriority`priority<br/>`Call`call<br/> |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |

## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`controller<br/>`CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                               |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`controller<br/>                                                                                                                                                                                                       |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |
| Set min commission         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Perbill`new\_<br/>                                                                                                                                                                                                                       |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## Aleph

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                |
| -------------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------------------------------- |
| Set emergency finalizer          |        |           |                  |         | `AuthorityId`emergency_finalizer<br/>                    |
| Schedule finality version change |        |           |                  |         | `Version`version_incoming<br/>`SessionIndex`session<br/> |

## Elections

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                             |
| ---------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| Change validators      |        |           |                  |         | `OptionVecAccountId`reserved_validators<br/>`OptionVecAccountId`non_reserved_validators<br/>`OptionCommitteeSeats`committee_size<br/> |
| Set elections openness |        |           |                  |         | `ElectionOpenness`openness<br/>                                                                                                       |

## Treasury

| Name             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                       |
| ---------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------- |
| Propose spend    |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        |           |                  |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        |           |                  |         | `Compactu32`proposal_id<br/>                                    |

## Vesting

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------------------------------------------- |
| Vest                  |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                          |
| Vest other            |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Sudo

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                   |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------- |
| Sudo                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>                             |
| Sudo unchecked weight |        | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |

## Contracts

| Name                             | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                       |
| -------------------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call old weight                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>            |
| Instantiate with code old weight |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>         |
| Instantiate old weight           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Vecu8`data<br/>`Vecu8`salt<br/> |
| Upload code                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Determinism`determinism<br/>                                                                 |
| Remove code                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code                         |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
| Call                             |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>                |
| Instantiate with code            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>             |
| Instantiate                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/>     |

## NominationPools

| Name                   | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                    |
| ---------------------- | ------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Join                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`PoolId`pool_id<br/>                                                                                                                              |
| Bond extra             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BondExtraBalanceOfT`extra<br/>                                                                                                                                              |
| Claim payout           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                                                                                                              |
| Unbond                 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`CompactBalance`unbonding_points<br/>                                                                                                 |
| Pool withdraw unbonded |        | :heavy_check_mark: | :heavy_check_mark: |                    | `PoolId`pool_id<br/>`u32`num_slashing_spans<br/>                                                                                                                             |
| Withdraw Unbonded      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`member_account<br/>`u32`num_slashing_spans<br/>                                                                                                          |
| Create                 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`state_toggler<br/>                                             |
| Create with pool id    |        | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>`AccountIdLookupOfT`root<br/>`AccountIdLookupOfT`nominator<br/>`AccountIdLookupOfT`state_toggler<br/>`PoolId`pool_id<br/>                         |
| Nominate               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`VecAccountId`validators<br/>                                                                                                                            |
| Set state              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`PoolState`state<br/>                                                                                                                                    |
| Set metadata           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`Vecu8`metadata<br/>                                                                                                                                     |
| Set configs            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_join_bond<br/>`ConfigOpBalanceOfT`min_create_bond<br/>`ConfigOpu32`max_pools<br/>`ConfigOpu32`max_members<br/>`ConfigOpu32`max_members_per_pool<br/> |
| Update roles           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>`ConfigOpAccountId`new_root<br/>`ConfigOpAccountId`new_nominator<br/>`ConfigOpAccountId`new_state_toggler<br/>                                           |
| Chill                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `PoolId`pool_id<br/>                                                                                                                                                         |

## Identity

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                       |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar     |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity      |        |           |                  |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs          |        |           |                  |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity    |        |           |                  |         |                                                                                                                 |
| Request judgement |        |           |                  |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request    |        |           |                  |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee           |        |           |                  |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id    |        |           |                  |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields        |        |           |                  |         | `Compactu32`index<br/>`IdentityFields`fields<br/>                                                               |
| Provide judgement |        |           |                  |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity     |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub           |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub          |        |           |                  |         |                                                                                                                 |

## CommitteeManagement

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                   |
| --------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Set ban config        |        |           |                  |         | `Optionu8`minimal_expected_performance<br/>`Optionu32`underperformed_session_count_threshold<br/>`Optionu32`clean_session_counter_delay<br/>`OptionEraIndex`ban_period<br/> |
| Ban from committee    |        |           |                  |         | `AccountId`banned<br/>`Vecu8`ban_reason<br/>                                                                                                                                |
| Cancel ban            |        |           |                  |         | `AccountId`banned<br/>                                                                                                                                                      |
| Set lenient threshold |        |           |                  |         | `u8`threshold_percent<br/>                                                                                                                                                  |
