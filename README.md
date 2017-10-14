# WebBinaryCompression
Due to my obsession with resource optimization, a while ago I thought: 
*making the internet connection faster is certainly a good thing, but why not
reduce what we send too?*

This project aims to work on the second part of my thought: make the internet
**smaller**.

## How does it work
The very basic idea is that, while HTML is *human-readable*, it is **internet
connection greedy**, as a lot of unnecessary bytes are send over the network.
To solve this problem it is sufficient to translate HTML to a more compact
representation which operates on bytes instead of characters.

For instance the `action` attribute of a generic `form` shall be translated to
it's single byte equivalent `0x09`, saving some precious bytes.

Of course it is required to add a little of semantic, so each (group of)
equivalent is precedeed by a special byte indicating it's type.
For instance we won't have just `action` but `attribute, action`, which
translates to `0x04 0x09`.

The type is not strictly required as each element may have a different
translation, but without it the required number of bytes to represent the whole
HTML would *explode*. By means of a type instead, it is possible to subdivide
the HTML into macro-groups (for instance *tags*, *attributes*, *events*, etc.)
in which there will be equivalent overlapping.

Once a group ends, a special ending byte (`0x00`) is emitted, for instance the
group `required checked` will be translated to `0x04 0x5A 0x11 0x00`.

Due to the fact that some developer may use non-standard HTML symbols, when the
parser cannot find an equivalent for a given string, it is marked as text and
copied *as-is*. By this way the algorithm is quite resilient.

A special case goes for multi-byte values, since most processor are *little endian*,
this algorithm uses little endian as well.

## Next steps
Right now only attributes (with every possible type of value) have been encoded.

First of all, it is required to complete the whole HTML, then a similar algorithm
for CSS will be implemented as well.

## Contribute
Everyone can contribute. Proofreading the documentation, bug-hunting, profiling,
spread the word.
**Everything is good**.

It like to put some special attenction to this points anyway:
* Test if output are correct
* Test on a big endian architecture
* Profile
* Implement SIMD