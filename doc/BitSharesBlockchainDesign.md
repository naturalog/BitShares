BitShares Blockchain Design
===========================

Overview
--------

The *BitShares’* blockchain has many common properties with the *Bitcoin’*s one. It is built upon transactions containing inputs and outputs, outputs being marked as spent or unspent, returning change and so on as described on this document. One may also refer to the Bitcoin documentation for additional explanations about this concept.

Main differences between Bitcoin’s blockchain and BitShare’s are:

* There can be several assets types, such as BitBTC, BitUSD, BitGOLD and so on.
* Every output spending is coupled with a claim.

Block
-----

A *block* is basically a list of transactions.

Each block contains:
* Block header

The block header contains:
* `block_id`: a unique integer block identifier.
* `version`: software version.
* `prev`: the id of the previous block on the chain.
* `block_num`: the sequential id of the block on the chain (?).
* `timestamp`: creation time of block up to resolution of seconds, does not have to be accurate.
* `total shares`: total BitShares transacted onthe block.
* `total_coindays_destroyed`: a measure of volume. Taking the transactions volume multiplied by the number of days since the last trasactions regarding its inputs.
* transaction Merkle root: required for light client validation (?)

the `block_proof` is a `block header`, with additional field representing the proof of work in terms of Merkle brance + nonce.

A `block` contains the `block_proof` information (so it automatically contains a `block header`), together with a `block state` structure. On BitShares, since we do not want our blockchain to grow to huge dimensions, any pending transaction will cost 5% dividend after 1 year unless the user has ran their client once.

A `full block` is a block together with a list of all included transactions.

Transactions

A transaction is built up of:
* inputs: an array of inputs which are unspent outputs (addresses that are not marked as spent) in which the transaction withdraws assets from. The transaction should be signed using the private keys of those addresses.
* outputs: an array of transaction’s outputs, which is basically the recipient address with or without one original address for the change if any.

Claims

Unlike Bitcoin, BitShares supports several types of spending an output. Every spending is coupled with a Claim. Claim is an abstract type with concrete descendants which are currently:

    claim_by_signature: output can be spent provided its private key.
    claim_by_bid: output can be spent only when a buyer and a seller was matched.
    claim_by_cover: output can be spent only by releasing loan’s collaterals.
     (TODO: ADD MORE).

Main Classes

Main Classes (TODO: explain them):

    trx_input: transaction input
    trx_output: transaction output
    asset: amount + asset type


