# 调整delay的参数在b.sh中'
g++ -std=c++11 yz_wash.cpp -o _yz_wash
./_yz_wash
g++ -std=c++11 yz_to_csv.cpp -o _yz_to_csv
./_yz_to_csv 500 # 可调参数，grid的大小(mm)，越大join results越多
mv raw.csv raw.csv
g++ -std=c++11 gen_arr_t.cpp -o _gen_arr_t
./_gen_arr_t raw.csv res.csv
g++ -std=c++11 split_streams.cpp -o _split_streams
./_split_streams