# Aleph Zero  4.12.x

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
|Schedule |    |   |   | `BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> |
|Schedule named |    |   |   | `Vecu8` id <br/>`BlockNumber` when <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Cancel named |    |   |   | `Vecu8` id <br/> |
|Schedule after |    |   |   | `BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |
|Schedule named after |    |   |   | `Vecu8` id <br/>`BlockNumber` after <br/>`OptionschedulePeriodBlockNumber` maybe_periodic <br/>`schedulePriority` priority <br/>`Call` call <br/> |

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
|Set staking limits |    |   |   | `Balance` min_nominator_bond <br/>`Balance` min_validator_bond <br/>`Optionu32` max_nominator_count <br/>`Optionu32` max_validator_count <br/>`OptionPercent` threshold <br/> |
|Chill other |    |   |   | `AccountId` controller <br/> |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## Elections

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Change members |    | :heavy_check_mark: |   | `VecAccountId` members <br/> |

## Treasury

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Propose spend |    |   |   | `CompactBalance` amount <br/>`LookupasStaticLookupSource` beneficiary <br/> |
|Reject proposal |    |   |   | `Compactu32` proposal_id <br/> |
|Approve proposal |    |   |   | `Compactu32` proposal_id <br/> |

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

