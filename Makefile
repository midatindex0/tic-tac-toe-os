all:
	cd src/ && make

clean:
	cd src/ && make clean

clean-img:
	rm os.bin

run:
	cd src/ && make run

img:
	cd src/ && make
	cp src/os-image.bin os.bin
	make clean