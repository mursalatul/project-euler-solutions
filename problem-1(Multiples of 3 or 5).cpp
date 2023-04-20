#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

// ll mulsum(ll n)
// {
//     // manually check (time complexity: O(n))
//     ll s = 0, mul_of_3 = 3, mul_of_5 = 5;
//     while (mul_of_3 < n || mul_of_5 < n)
//     {
//         if (mul_of_3 < n)
//         {
//             s += mul_of_3;
//         }
//         if (mul_of_5 < n && (mul_of_5 / 5) % 3 != 0)
//         {
//             s += mul_of_5;
//         }
//         mul_of_3 += 3;
//         mul_of_5 += 5;
//     }
//     return s;
// }

ll columns(ll num_of_muls)
{
    if (num_of_muls & 1)
        num_of_muls++; // adding one zero
    // row will be always 2
    // so if we divide number of multiples by 2 then we will find the number of columns.
    return num_of_muls / 2;
}

ll columnSum(ll base, ll num_of_muls)
{
    if (num_of_muls & 1)
        // if num of multiples are odd then it cant be evenly divided by 2 rows.
        // so we need a heading 0. in this case we just need highest mul(base * num_of_muls)
        // cause here base will be 0 and 0 + (base * num_of_muls) = base * num_of_muls
        return base * num_of_muls;
    else
        // if num of multiples are even then it can be evenly divided by 2 rows.
        // as a result the sum of the column will be the lowest mul(base) and
        // hightest mul (base * num_of_muls)
        return base + (base * num_of_muls);
}

ll mulsum1(ll n)
{
    // number of multiples of 3, 5, and 15. (considering 15 cause 3x5 = 15 will generate its mutiples as well.)
    ll num_of_multiples_3 = n / 3;
    ll num_of_multiples_5 = n / 5;
    ll num_of_multiples_15 = n / 15;

    // n/2
    ll num_of_columns_3 = columns(num_of_multiples_3);
    ll num_of_columns_5 = columns(num_of_multiples_5);
    ll num_of_columns_15 = columns(num_of_multiples_15);

    // n + 1
    ll sum_ofa_column_3 = columnSum(3, num_of_multiples_3);
    ll sum_ofa_column_5 = columnSum(5, num_of_multiples_5);
    ll sum_ofa_column_15 = columnSum(15, num_of_multiples_15);

    // (n/2) *(n+1)
    ll sum_of_multiples_3 = num_of_columns_3 * sum_ofa_column_3;
    ll sum_of_multiples_5 = num_of_columns_5 * sum_ofa_column_5;
    ll sum_of_multiples_15 = num_of_columns_15 * sum_ofa_column_15;

    //
    return sum_of_multiples_3 + sum_of_multiples_5 - sum_of_multiples_15;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // pre-generating all the answers and storing in an array
    // const ll BASE = 1000000000;
    // ll arr[BASE + 1];
    // arr[0] = 0;
    // ll s = 0;
    // for (ll i = 1; i <= BASE; i++)
    // {
    //     ll j = i - 1;
    //     if (j % 3 == 0)
    //     {
    //         s += j;
    //     }
    //     else if (j % 5 == 0)
    //     {
    //         s += j;
    //     }
    //     arr[i] = s;
    // }
    //
    ll t;
    for (cin >> t; t--;)
    {
        ll n;
        cin >> n;
        // decrease 1 cause we need divisor sum less then n
        n--;
        cout << mulsum1(n) << '\n';
    }
    return 0;
}