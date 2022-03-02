# RTI Connext Micro 2.4.14 "hands-on" exercises

The instructions below reference the `RTIMEHOME` and `RTIMEARCH` environment variables-- these hold the values of the Micro installation directory and the platform architecture, respectively. In the example below, `/home/don/rti_connext_dds_micro-2.4.14` is the installation directory, and the platform architecture is `x64Linux4gcc7.3.0`:
```
export RTIMEHOME=/home/don/rti_connext_dds_micro-2.4.14
export RTIMEARCH=x64Linux4gcc7.3.0
```

## Exercise 00

Because Micro is delivered as source, we need to build the libraries.

```
$ cd $RTIMEHOME

$ $RTIMEHOME/resource/scripts/rtime-make --target Linux --name ${RTIMEARCH} -G "Unix Makefiles" --build --config Release

$ $RTIMEHOME/resource/scripts/rtime-make --target Linux --name ${RTIMEARCH} -G "Unix Makefiles" --build --config Debug
```
## Exercise 01

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
$ ./objs/x64Linux5gcc9.3.0/example_publisher
```
- In a second terminal 
```
$ ./objs/x64Linux5gcc9.3.0/ProximityDatatype_subscriber
```