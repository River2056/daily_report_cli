exe_name:=cli_y

all: run
install: build_install

clean:
	rm -rf ./build
	mkdir build

build: clean
	cmake -S . -B ./build
	cmake --build ./build

build_install: clean
	cmake -S . -B ./build
	cmake --build ./build --config Release --target install

run: build
	cd ./build/app/Debug/ && ./$(exe_name).exe

generate: clean
	cmake -S . -B ./build -GNinja
	mv ./build/compile_commands.json .
