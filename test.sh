#!/bin/bash

sudo wrmsr -a 0x186 0x4101a1 
sudo wrmsr -a 0x187 0x4102a1
sudo wrmsr -a 0x188 0x4104a1
sudo wrmsr -a 0x189 0x4108a1
sudo wrmsr -a 0x18a 0x4110a1
sudo wrmsr -a 0x18b 0x4120a1
sudo wrmsr -a 0x18c 0x4140a1
sudo wrmsr -a 0x18d 0x4180a1


while :
do
	sudo wrmsr -a 0xc1 0x00
	sudo wrmsr -a 0xc2 0x00
	sudo wrmsr -a 0xc3 0x00
	sudo wrmsr -a 0xc4 0x00
	sudo wrmsr -a 0xc5 0x00
	sudo wrmsr -a 0xc6 0x00
	sudo wrmsr -a 0xc7 0x00
	sudo wrmsr -a 0xc8 0x00

	sudo rdmsr -a 0xc1 | sed -n '2p' # 2 core execution port 0
	sudo rdmsr -a 0xc2 | sed -n '2p' # 2 core execution port 1
	sudo rdmsr -a 0xc3 | sed -n '2p' # 2 core execution port 2
	sudo rdmsr -a 0xc4 | sed -n '2p' # 2 core execution port 3
	sudo rdmsr -a 0xc5 | sed -n '2p' # 2 core execution port 4
	sudo rdmsr -a 0xc6 | sed -n '2p' # 2 core execution port 5
	sudo rdmsr -a 0xc7 | sed -n '2p' # 2 core execution port 6
	sudo rdmsr -a 0xc8 | sed -n '2p' # 2 core execution port 7
	
	echo -e "\nnext test\n"
	sleep 1	
done
 
