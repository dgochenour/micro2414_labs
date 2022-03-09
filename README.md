# RTI Connext Micro 2.4.14 "hands-on" exercises

The instructions below reference the `RTIMEHOME` and `RTIMEARCH` environment variables-- these hold the values of the Micro installation directory and the platform architecture, respectively. In the example below, `/home/don/rti_connext_dds_micro-2.4.14` is the installation directory, and the platform architecture is `x64Linux4gcc7.3.0`:
```
export RTIMEHOME=/home/don/rti_connext_dds_micro-2.4.14
export RTIMEARCH=x64Linux4gcc7.3.0
```

## Exercise 00: build platform libraries

Because Micro is delivered as source, we need to build the libraries.

```
$ cd $RTIMEHOME

$ $RTIMEHOME/resource/scripts/rtime-make --target Linux --name ${RTIMEARCH} -G "Unix Makefiles" --build --config Release

$ $RTIMEHOME/resource/scripts/rtime-make --target Linux --name ${RTIMEARCH} -G "Unix Makefiles" --build --config Debug
```
## Exercise 01: generate type support and example code

1) Design IDL file to contain one type called "Pose"
2) Generate type support code with `rtiddsgen`
```
$ cd 01
$ $RTIMEHOME/rtiddsgen/scripts/rtiddsgen -micro -create typefiles -create makefiles -create examplefiles -language C++ -namespace example.idl
```

3) Build the example code
``` 
$ $RTIMEHOME/resource/scripts/rtime-make --config Release --build --name $RTIMEARCH --target Linux --source-dir . -G "Unix Makefiles" --delete
```

4) Run the as-generated example code, just as a sanity check
- In one terminal 
```
$ ./objs/x64Linux4gcc7.3.0/example_publisher
```
- In a second terminal 
```
$ ./objs/x64Linux4gcc7.3.0/ProximityDatatype_subscriber
```

## Exercise 02: introduce Admin Console

1) Add dummy data in the publisher, just so we aren't writing empty samples
2) Print some of the received data to stdout on the subscriber side
3) Generate XML version of the IDL and Increase resource limits to interoperate with Admin Console
  (https://community.rti.com/static/documentation/connext-micro/2.4.14/doc/html/usersmanual/micro_core.html#admin-console)


## Exercise 03: introduce Deadline QoS and on_requested_incompatible_qos callback

1) Modify the subscriber QoS so that it requests a Deadline.
2) Notice that data no longer flows... why? 
3) Correct QoS on the publisher side
4) Implement a listener callback on the subscriber side to inform the user about `requested_incompatible_qos` status