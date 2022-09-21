# Aleph Zero  9.30.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## Scheduler

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`BoxCallOrHashOfT` call <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## Staking

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Bond |    |   |   | `LookupasStaticLookupSource` controller <br/>`CompactBalance` amount <br/>`RewardDestination` payee <br/> |
|Bond extra |    |   |   | `CompactBalance` amount <br/> |
|Unbond |    |   |   | `CompactBalance` amount <br/> |
|Withdraw Unbonded |    |   |   | `u32` num_slashing_spans <br/> |
|Validate |    |   |   | `ValidatorPrefs` prefs <br/> |
|Nominate |    |   |   | `VecLookupasStaticLookupSource` targets <br/> |
|Chill |    |   |   |  |
|Set payee |    |   |   | `RewardDestination` payee <br/> |
|Set controller |    |   |   | `LookupasStaticLookupSource` controller <br/> |
|Set validator count |    |   |   | `Compactu32` new_ <br/> |
|Increase validator count |    |   |   | `Compactu32` additional <br/> |
|Scale validator count |    |   |   | `Percent` factor <br/> |
|Force no eras |    |   |   |  |
|Force new era |    |   |   |  |
|Set invulnerables |    |   |   | `VecAccountId` invulnerables <br/> |
|Force unstake |    |   |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Force new era always |    |   |   |  |
|Cancel deferred slash |    |   |   | `EraIndex` era <br/>`Vecu32` slash_indices <br/> |
|Payout stakers |    |   |   | `AccountId` validator_stash <br/>`EraIndex` era <br/> |
|Rebond |    |   |   | `CompactBalance` amount <br/> |
|Set history depth |    |   |   | `Compactu32` new_history_depth <br/>`Compactu32` era_items_deleted <br/> |
|Reap stash |    |   |   | `AccountId` stash <br/>`u32` num_slashing_spans <br/> |
|Kick |    |   |   | `VecLookupasStaticLookupSource` who <br/> |
|Set staking configs |    |   |   | `ConfigOpBalanceOfT` min_nominator_bond <br/>`ConfigOpBalanceOfT` min_validator_bond <br/>`ConfigOpu32` max_nominator_count <br/>`ConfigOpu32` max_validator_count <br/>`ConfigOpPercent` chill_threshold <br/>`ConfigOpPerbill` min_commission <br/> |
|Chill other |    |   |   | `AccountId` controller <br/> |
|Force apply min commission |    |   |   | `AccountId` validator_stash <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Aleph

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set emergency finalizer |    |   |   | `AuthorityId` emergency_finalizer <br/> |

## Elections

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Change validators |    |   |   | `OptionVecAccountId` reserved_validators <br/>`OptionVecAccountId` non_reserved_validators <br/>`OptionCommitteeSeats` committee_size <br/> |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    |   |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Spend |    |   |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Remove approval |    |   |   | `Compactu32` proposal_id <br/> |

## Vesting

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Vest |    | :heavy_check_mark: |   |  |
|Vest other |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/> |
|Vested transfer |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> |
|Force vested transfer |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` target <br/>`VestingInfo` schedule <br/> |
|Merge schedules |    | :heavy_check_mark: |   | `u32` schedule1_index <br/>`u32` schedule2_index <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |
|Force batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Sudo

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Sudo |    | :heavy_check_mark: |   | `Call` call <br/> |
|Sudo unchecked weight |    | :heavy_check_mark: |   | `Call` call <br/>`Weight` weight <br/> |
|Set key |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` new_ <br/> |
|Sudo as |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Call` call <br/> |

## Contracts

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Call |    |   |   | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/>`Compactu64` gas_limit <br/>`OptionCompactBalanceOf` storage_deposit_limit <br/>`Vecu8` data <br/> |
|Instantiate with code |    |   |   | `CompactBalance` amount <br/>`Compactu64` gas_limit <br/>`OptionCompactBalanceOf` storage_deposit_limit <br/>`Vecu8` code <br/>`Vecu8` data <br/>`Vecu8` salt <br/> |
|Instantiate |    |   |   | `CompactBalance` amount <br/>`Compactu64` gas_limit <br/>`OptionCompactBalanceOf` storage_deposit_limit <br/>`CodeHash` code_hash <br/>`Bytes` data <br/>`Bytes` salt <br/> |
|Upload code |    |   |   | `Vecu8` code <br/>`OptionCompactBalanceOf` storage_deposit_limit <br/> |
|Remove code |    |   |   | `CodeHash` code_hash <br/> |
|Set code |    |   |   | `LookupasStaticLookupSource` dest <br/>`CodeHash` code_hash <br/> |

## NominationPools

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Join |    |   |   | `Compactu128` amount <br/>`PoolId` pool_id <br/> |
|Bond extra |    |   |   | `BondExtraBalanceOfT` extra <br/> |
|Claim payout |    |   |   |  |
|Unbond |    |   |   | `AccountId` member_account <br/>`Compactu128` unbonding_points <br/> |
|Pool withdraw unbonded |    |   |   | `PoolId` pool_id <br/>`u32` num_slashing_spans <br/> |
|Withdraw Unbonded |    |   |   | `AccountId` member_account <br/>`u32` num_slashing_spans <br/> |
|Create |    |   |   | `Compactu128` amount <br/>`AccountId` root <br/>`AccountId` nominator <br/>`AccountId` state_toggler <br/> |
|Nominate |    |   |   | `PoolId` pool_id <br/>`VecAccountId` validators <br/> |
|Set state |    |   |   | `PoolId` pool_id <br/>`PoolState` state <br/> |
|Set metadata |    |   |   | `PoolId` pool_id <br/>`Vecu8` metadata <br/> |
|Set configs |    |   |   | `ConfigOpBalanceOfT` min_join_bond <br/>`ConfigOpBalanceOfT` min_create_bond <br/>`ConfigOpu32` max_pools <br/>`ConfigOpu32` max_members <br/>`ConfigOpu32` max_members_per_pool <br/> |
|Update roles |    |   |   | `PoolId` pool_id <br/>`ConfigOpAccountId` new_root <br/>`ConfigOpAccountId` new_nominator <br/>`ConfigOpAccountId` new_state_toggler <br/> |
|Chill |    |   |   | `PoolId` pool_id <br/> |

## Identity

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Add registrar |    |   |   | `AccountId` account <br/> |
|Set identity |    |   |   | `BoxIdentityInfoMaxAdditionalFields` info <br/> |
|Set subs |    |   |   | `VecTupleAccountIdData` subs <br/> |
|Clear identity |    |   |   |  |
|Request judgement |    |   |   | `Compactu32` reg_index <br/>`Compactu128` max_fee <br/> |
|Cancel request |    |   |   | `RegistrarIndex` reg_index <br/> |
|Set fee |    |   |   | `Compactu32` index <br/>`Compactu128` fee <br/> |
|Set account id |    |   |   | `Compactu32` index <br/>`AccountId` new_ <br/> |
|Set fields |    |   |   | `Compactu32` index <br/>`IdentityFields` fields <br/> |
|Provide judgement |    |   |   | `Compactu32` reg_index <br/>`LookupasStaticLookupSource` target <br/>`JudgementBalanceOfT` judgement <br/> |
|Kill identity |    |   |   | `LookupasStaticLookupSource` target <br/> |
|Add sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Rename sub |    |   |   | `LookupasStaticLookupSource` sub <br/>`Data` data <br/> |
|Remove sub |    |   |   | `LookupasStaticLookupSource` sub <br/> |
|Quit sub |    |   |   |  |

