# closest-pair-doubling

> The implementation in C++ of the closest-pair doubling algorithm which finds the smallest distance between two points in a metric space in *O(n log n)* time without directly using the points' coordinates.  

Thanks to the work of Anil Maheshwari, Wolfgang Mulzer and Michiel Smid.
*A Simple Randomized O(N log N)–Time Closest-Pair Algorithm in Doubling Metrics*.
https://arxiv.org/abs/2004.05883

### 📝 [Project report](https://github.com/ThangMinhCao/closestpairdoubling/blob/master/report/project_report/Project_Report.pdf)


## Prerequisites

- [cmake >= 3.16](https://cmake.org/) 

## Install

```sh
git clone git@github.com:ThangMinhCao/closestpairdoubling.git
cd closestpairdoubling
cmake .
make
```

## Testing Program 

In the directory of the repo:
```sh
./closestpairdoubling
```

## Author

**Minh Thang Cao**

* Website: https://
* Github: [@ThangMinhCao](https://github.com/ThangMinhCao)
* LinkedIn: [@minhthangcao](https://linkedin.com/in/minhthangcao)


├── cmake-build-debug
│   ├── closest_pair_doubling
│   ├── ClosestPairDoubling.cbp
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.17.3
│   │   │   ├── CMakeCCompiler.cmake
│   │   │   ├── CMakeCXXCompiler.cmake
│   │   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   │   ├── CMakeSystem.cmake
│   │   │   ├── CompilerIdC
│   │   │   │   ├── a.out
│   │   │   │   ├── CMakeCCompilerId.c
│   │   │   │   └── tmp
│   │   │   └── CompilerIdCXX
│   │   │       ├── a.out
│   │   │       ├── CMakeCXXCompilerId.cpp
│   │   │       └── tmp
│   │   ├── clion-environment.txt
│   │   ├── clion-log.txt
│   │   ├── closest_pair_doubling.dir
│   │   │   ├── build.make
│   │   │   ├── cmake_clean.cmake
│   │   │   ├── CXX.includecache
│   │   │   ├── DependInfo.cmake
│   │   │   ├── depend.internal
│   │   │   ├── depend.make
│   │   │   ├── flags.make
│   │   │   ├── link.txt
│   │   │   ├── progress.make
│   │   │   ├── src
│   │   │   │   ├── closest_pair_doubling.cpp.o
│   │   │   │   ├── kth_smallest.cpp.o
│   │   │   │   ├── main.cpp.o
│   │   │   │   └── point_list.cpp.o
│   │   │   ├── test
│   │   │   │   ├── algorithm_runner.cpp.o
│   │   │   │   └── program.cpp.o
│   │   │   └── utils
│   │   │       ├── 2d_problem
│   │   │       │   ├── 2d_problem.cpp.o
│   │   │       │   └── merge_sort.cpp.o
│   │   │       ├── non_Euclidean_problem
│   │   │       │   ├── src
│   │   │       │   │   ├── closest_pair_non_Eu.cpp.o
│   │   │       │   │   └── kth_smallest_non_Eu.cpp.o
│   │   │       │   └── test
│   │   │       │       ├── algorithm_runner_non_Eu.cpp.o
│   │   │       │       └── program_non_Eu_part.cpp.o
│   │   │       └── user_controller
│   │   │           └── user_input_controller.cpp.o
│   │   ├── cmake.check_cache
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── CMakeOutput.log
│   │   ├── CMakeTmp
│   │   ├── Makefile2
│   │   ├── Makefile.cmake
│   │   ├── progress.marks
│   │   └── TargetDirectories.txt
│   ├── cmake_install.cmake
│   ├── Makefile
│   ├── non_Eu_running_time.txt
│   ├── running_time_data.txt
│   └── sep_ann_loop_times.txt
├── CMakeLists.txt
├── include
│   ├── closest_pair_doubling.h
│   ├── kth_smallest.h
│   ├── point.h
│   ├── point_list.h
│   └── random_generator.h
├── LICENSE
├── README.md
├── report
│   ├── images_&_data
│   │   ├── closest_pair
│   │   │   ├── brute_force
│   │   │   │   ├── non_Eu_running_time_data.txt
│   │   │   │   ├── outputs
│   │   │   │   │   ├── BF_200k.png
│   │   │   │   │   ├── BF_300k.png
│   │   │   │   │   ├── BF_400k.png
│   │   │   │   │   ├── BF_500k.png
│   │   │   │   │   ├── BF_non_Eu_2k.png
│   │   │   │   │   ├── BF_non_Eu_4k.png
│   │   │   │   │   └── BF_non_Eu_8k.png
│   │   │   │   └── running_time_data.txt
│   │   │   ├── grid_generation
│   │   │   │   ├── grid_sepann_data.txt
│   │   │   │   ├── output_images_1k_closest
│   │   │   │   │   ├── grid_100k.png
│   │   │   │   │   ├── grid_200k.png
│   │   │   │   │   ├── grid_300k.png
│   │   │   │   │   ├── grid_400k.png
│   │   │   │   │   ├── grid_500k.png
│   │   │   │   │   ├── grid_600k.png
│   │   │   │   │   └── grid_700k.png
│   │   │   │   └── outputs.txt
│   │   │   ├── non_Euclidean_metrics
│   │   │   │   ├── output_images_100_to_4900
│   │   │   │   │   ├── strange_1000.png
│   │   │   │   │   ├── strange_100.png
│   │   │   │   │   ├── strange_1100.png
│   │   │   │   │   ├── strange_1200.png
│   │   │   │   │   ├── strange_1300.png
│   │   │   │   │   ├── strange_1400.png
│   │   │   │   │   ├── strange_1500.png
│   │   │   │   │   ├── strange_1600.png
│   │   │   │   │   ├── strange_1700.png
│   │   │   │   │   ├── strange_1800.png
│   │   │   │   │   ├── strange_1900.png
│   │   │   │   │   ├── strange_2000.png
│   │   │   │   │   ├── strange_200.png
│   │   │   │   │   ├── strange_2100.png
│   │   │   │   │   ├── strange_2200.png
│   │   │   │   │   ├── strange_2300.png
│   │   │   │   │   ├── strange_2400.png
│   │   │   │   │   ├── strange_2500.png
│   │   │   │   │   ├── strange_2600.png
│   │   │   │   │   ├── strange_2700.png
│   │   │   │   │   ├── strange_2800.png
│   │   │   │   │   ├── strange_2900.png
│   │   │   │   │   ├── strange_3000.png
│   │   │   │   │   ├── strange_300.png
│   │   │   │   │   ├── strange_3100.png
│   │   │   │   │   ├── strange_3200.png
│   │   │   │   │   ├── strange_3300.png
│   │   │   │   │   ├── strange_3400.png
│   │   │   │   │   ├── strange_3500.png
│   │   │   │   │   ├── strange_3600.png
│   │   │   │   │   ├── strange_3700.png
│   │   │   │   │   ├── strange_3800.png
│   │   │   │   │   ├── strange_3900.png
│   │   │   │   │   ├── strange_4000.png
│   │   │   │   │   ├── strange_400.png
│   │   │   │   │   ├── strange_4100.png
│   │   │   │   │   ├── strange_4200.png
│   │   │   │   │   ├── strange_4300.png
│   │   │   │   │   ├── strange_4400.png
│   │   │   │   │   ├── strange_4500.png
│   │   │   │   │   ├── strange_4600.png
│   │   │   │   │   ├── strange_4700.png
│   │   │   │   │   ├── strange_4800.png
│   │   │   │   │   ├── strange_4900.png
│   │   │   │   │   ├── strange_500.png
│   │   │   │   │   ├── strange_600.png
│   │   │   │   │   ├── strange_700.png
│   │   │   │   │   ├── strange_800.png
│   │   │   │   │   └── strange_900.png
│   │   │   │   ├── outputs.txt
│   │   │   │   ├── outputs_with_dist_counter.txt
│   │   │   │   └── sep_ann_data_non_Euclidean.txt
│   │   │   └── random_generation
│   │   │       ├── output
│   │   │       │   ├── random_100k.png
│   │   │       │   ├── random_1mil.png
│   │   │       │   ├── random_200k.png
│   │   │       │   ├── random_300k.png
│   │   │       │   ├── random_400k.png
│   │   │       │   ├── random_500k.png
│   │   │       │   ├── random_600k.png
│   │   │       │   ├── random_700k.png
│   │   │       │   ├── random_800k.png
│   │   │       │   └── random_900k.png
│   │   │       ├── outputs.txt
│   │   │       ├── random_sep_ann_data_100kto1000k_100kStep.txt
│   │   │       └── random_sep_ann_data_500kto8000k_times2Step.txt
│   │   └── kth_smallest
│   │       └── 100m.png
│   └── project_report
│       ├── grid_data.txt
│       ├── non_Eu_data.txt
│       ├── non_Eu_data_with_dist_count.txt
│       ├── preamble.tex
│       ├── Project_Report.log
│       ├── Project_Report.pdf
│       ├── Project_Report.Rmd
│       ├── Project_Report.tex
│       └── random_data.txt
├── src
│   ├── closest_pair_doubling.cpp
│   ├── kth_smallest.cpp
│   ├── main.cpp
│   └── point_list.cpp
├── test
│   ├── algorithm_runner.cpp
│   ├── algorithm_runner.h
│   ├── program.cpp
│   └── program.h
└── utils
    ├── 2d_problem
    │   ├── 2d_problem.cpp
    │   ├── 2d_problem.h
    │   ├── merge_sort.cpp
    │   └── merge_sort.h
    ├── non_Euclidean_problem
    │   ├── include
    │   │   ├── closest_pair_non_Eu.h
    │   │   ├── kth_smallest_non_Eu.h
    │   │   ├── point_list_non_Eu.h
    │   │   └── point_non_Eu.h
    │   ├── src
    │   │   ├── closest_pair_non_Eu.cpp
    │   │   └── kth_smallest_non_Eu.cpp
    │   └── test
    │       ├── algorithm_runner_non_Eu.cpp
    │       ├── algorithm_runner_non_Eu.h
    │       ├── program_non_Eu_part.cpp
    │       └── program_non_Eu_part.h
    └── user_controller
        ├── user_input_controller.cpp
        └── user_input_controller.h

## License

Copyright © 2020 [Minh Thang Cao](https://github.com/ThangMinhCao).<br />
This project is [MIT](https://github.com/ThangMinhCao/closestpairdoubling/blob/master/LICENSE) licensed.
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/ThangMinhCao/closest-pair-doubling/blob/master/LICENSE)
