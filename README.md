# closest-pair-doubling

> The implementation in C++ of the closest-pair doubling algorithm which finds the smallest distance between pairs of points in any multi-dimensional metric space in *O(n log n)* time without directly using the points' coordinates.  

Thanks to the work of Anil Maheshwari, Wolfgang Mulzer and Michiel Smid.
*A Simple Randomized O(N log N)–Time Closest-Pair Algorithm in Doubling Metrics*.
https://arxiv.org/abs/2004.05883

### 📝 [Project report](https://github.com/ThangMinhCao/closestpairdoubling/blob/master/report/project_report/Project_Report.pdf)

### :page_with_curl: [Outputs and data](https://github.com/ThangMinhCao/closest-pair-doubling/tree/master/report/images_%26_data)

## Prerequisites

- [cmake >= 3.16](https://cmake.org/) 
- [boost >= 1.69.0](https://www.boost.org/)

## Notes

Because of very large base cases of the algorithm on Euclidean spaces with dimension more than 3D (>= 3 000 000 points) which causes extremely long running time, my test examples and the program only deals with 2D Euclidean spaces.

## Install

```sh
git clone git@github.com:ThangMinhCao/closestpairdoubling.git
cd closestpairdoubling
cmake .
make
```

## Test the program 

In the cloned directory of the repo:
```sh
./closestpairdoubling
```

## Author

**Minh Thang Cao**

* Github: [@ThangMinhCao](https://github.com/ThangMinhCao)
* LinkedIn: [@minhthangcao](https://linkedin.com/in/minhthangcao)

## License

Copyright © 2020 [Minh Thang Cao](https://github.com/ThangMinhCao).<br />
This project is [MIT](https://github.com/ThangMinhCao/closestpairdoubling/blob/master/LICENSE) licensed.
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/ThangMinhCao/closest-pair-doubling/blob/master/LICENSE)
