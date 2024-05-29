dependency:
	    cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphimage.png
prepare:
	    rmdir /s /q build
	    mkdir build
conan_d:
	rmdir /s /q build
	mkdir build
	cd build && conan install .. -s build_type=Debug -s compiler.cppstd=17 --output-folder=. --build missing
conan_r:
	rmdir /s /q build
	mkdir build
	cd build && conan install .. -s build_type=Release -s compiler.cppstd=17 --output-folder=. --build missing
