Small experiment for topic discussed in Networks class.

This is a simple analog of bitstuffing (character stuffing in this example) in order to allow for variable length encoding using a keyword in a header that must not appear elsewhere in the payload.

Note: In this implementation, `startToken` must not have a duplicated prefix. To implement this, consider using an [Aho-Corasick Automaton](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm). Thanks Niema! Currently, a `startToken` like "jarjarbinks" will fail if the string "jarjarjarbinks" appears in the message.

Note: Don't include spaces in your inputs, it will only take the first word, and the bash script won't accept it.

Usage: 
```
chmod +x char_stuffer_test.sh
```
```
./char_stuffer_test.sh <message_without_spaces>
```
The output will tell you the link level message that was sent between the encoder and decoder.
