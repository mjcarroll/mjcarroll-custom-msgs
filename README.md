
Example to exercise the new gazebo messages generation pipeline:

```
# No args: lists all available message types
➜  mjcarroll-custom-msgs ./mjcarroll-custom-msgs
...

# Get a custom message definition
➜  mjcarroll-custom-msgs ./mjcarroll-custom-msgs mjcarroll.foo.MyBytes
Name: mjcarroll.foo.MyBytes
File: mjcarroll/foo/my_bytes.proto

message MyBytes {
  bytes data = 2;
}

# An example of a message that depends on gz-msgs
➜  mjcarroll-custom-msgs ./mjcarroll-custom-msgs mjcarroll.foo.Depends
Name: mjcarroll.foo.Depends
File: mjcarroll/foo/depends.proto

message Depends {
  .gz.msgs.Header header = 1;
}

# An example of a message that depends on another message target
➜  mjcarroll-custom-msgs ./mjcarroll-custom-msgs mjcarroll2.foo.Bytes  
Name: mjcarroll2.foo.Bytes
File: mjcarroll2/foo/depends2.proto

message Bytes {
  .mjcarroll.foo.Depends data = 1;
}
```
