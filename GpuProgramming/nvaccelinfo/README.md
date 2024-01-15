# GPU Info

To get gpu info
```sh
nvaccelinfo
```
To see gpu nodes
```sh
nvidia-smi
```

Compile warmup code
```sh
nvc++ -mp=gpu warmUpDevice.cpp -o warmUpDevice
nvc++ -cuda cudaDeviceQuery.cpp -o cudaDeviceQuery
```

