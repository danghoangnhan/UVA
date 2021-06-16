#include <bits/stdc++.h>

using namespace std;



int main(int argc, char){






    return 0;
}

// 求任兩點的最短距離，如果全部枚舉的話，時間複雜度n ^ 2，一定會TLE。

//     想法：
//     將所有點依x座標排序
//     從中間切開，將所有點分成左右兩個集合(設line為中線x座標)
//     左右兩邊各求出任兩點最小值a,
//     b，設d為min(a, b)
//     那麼現在只要枚舉(line + -d) 這範圍內的點有沒有比d還更小的值即可

//     遞迴定義：
//     divide(point_type a[], low, high)
//         求出a[low] ~a[high] 範圍內任兩點的最短距離
//     combine(point_type a[], low, mid, high, min_left, min_right)
//         d = min(min_left, min_right)
//             line = (a[mid].x + a[mid + 1].x) / 2 合併左右兩個集合，並確認在(line + -d) 的範圍內有沒有比d更小的值，最後回傳最小值
//                    更詳細圖解可參考KuoE0 : http : //www.slideshare.net/KuoE0/acmicpc-uva10245

//                                                   注意輸入輸出皆要用double