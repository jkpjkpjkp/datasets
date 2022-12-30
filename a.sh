# 调整delay的参数在b.sh中'
g++ -std=c++11 yz_wash.cpp -o _yz_wash
./_yz_wash
g++ -std=c++11 yz_to_csv.cpp -o _yz_to_csv
./_yz_to_csv 100 500 # 第一个参数是时间稀疏程度(ms)，第二个参数是网格大小(mm)
g++ -std=c++11 gen_arr_t.cpp -o _gen_arr_t
./_gen_arr_t _raw.csv _res.csv
g++ -std=c++11 split_streams.cpp -o _split_streams
./_split_streams