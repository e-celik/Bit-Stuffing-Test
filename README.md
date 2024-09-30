# Small experiment for topic discussed in Networks class.

This is a simple analog of bitstuffing (character stuffing in this example) in order to allow for variable length encoding using a keyword in a header that must not appear elsewhere in the payload.

Note: In this implementation, `startToken` must not have a duplicated prefix. To implement this, consider using an [Aho-Corasick Automaton](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm). Thanks Niema! Currently, a `startToken` like "jarjarbinks" will fail if the string "jarjarjarbinks" appears in the message.

Note: Don't include spaces in your inputs, it will only take the first word, and the bash script won't accept it.

## Explanation

In order to guarantee that the keyword doesn't appear in the payload, the encoder adds an extra symbol after any n-1 prefix of the keyword that may appear in the payload. The decoder removes this symbol, and the original message is completely preserved. 

Example:

Keyword: `start`
Message: `i_am_starting_to_enjoy_looking_at_the_stars`

The encoder will append the keyword as a header, and then add a 't' ('s'-1 in ASCII) after any appearance of "star."

The encoded message sent between the encoder and decoder will be:
`starti_am_starsting_to_enjoy_looking_at_the_starss`

Note that `start` does not appear anywhere other than the header in the message.

The decoder will then remove the header, and remove all characters that immeadiately follow an appearance of `star`.

This yields a succesful decoding of the original message.

## Usage: 
```
chmod +x char_stuffer_test.sh
```
```
./char_stuffer_test.sh <message_without_spaces>
```
The output will tell you the link level message that was sent between the encoder and decoder.
