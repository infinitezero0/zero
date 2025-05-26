#include <bits/stdc++.h>
#include <cstring>
#include <type_traits>
using namespace std;
//create fold 146j
namespace FastIO
{
    char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
    int p, p3 = -1;
    inline void flush()
    {
        fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
    }
    inline int getc()
    {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    void read() {}
    template <typename T>
        typename enable_if<is_same_v<T,double>>::type
        read_single(T& x){
            static const double pow10_neg[]={0,0.1,0.01,0.001,0.0001,
                0.00001,0.000001,0.0000001,0.00000001,0.000000001,0.0000000001};
            int f = 1;
            x = 0;
            char ch = getc();
            while (!isdigit(ch))
            {
                if(ch=='-') f=-1;
                ch = getc();
            }
            while (isdigit(ch))
            {
                x = x * 10 + ch - 48;
                ch = getc();
            }
            long long c=0,s=0;
            if (ch == '.')
            {
                ch = getc();
                while (isdigit(ch))
                {
                    s = (ch - 48)+(s<<3)+(s<<1);
                    c++;
                    ch = getc();
                }
            }
            x+=s*pow10_neg[c];
            x=x*f;
        }
    template <typename T>
        typename enable_if<(is_same_v<T,int> || is_same_v<T, long long>)>::type
        read_single(T& x){
            int f = 0;
            x = 0;
            char ch = getc();
            while (!isdigit(ch))
            {
                if (ch == '-')
                    f = 1;
                ch = getc();
            }
            while (isdigit(ch))
            {
                x = x * 10 + ch - 48;
                ch = getc();
            }
            x = f ? -x : x;
        }
    template <typename T>
        typename enable_if<is_same_v<T,string>>::type
         read_single(T& x){
            x.clear();
            char ch = getc();
            while (!isalpha(ch))
            {
                ch = getc();
            }
            while (isalpha(ch))
            {
                x+=ch;
                ch = getc();
            }
        }
    template <typename T, typename... T2>
         void read(T &x, T2 &... oth)
        {
            read_single(x);
            read(oth...);
        }
    void print() {
        flush();
    }
    int places=10;
    template <typename T>
        typename enable_if<is_same_v<T,double>>::type
        print_single(T x){
            if (p3 > 1 << 20)
                flush();
            if (x < 0)
                buf2[++p3] = '-', x = -x;
            int t = (int)x;
            do
            {
                a[++p] = t % 10 + '0';
            } while (t /= 10);
            do
            {
                buf2[++p3] = a[p];
            } while (--p);
            buf2[++p3] = '.';
            double d = x - (int)x;
            for(int i=0;i<places;i++){
                d *= 10;
                buf2[++p3] = (int)d + '0';
                d -= (int)d;
            }
            buf2[++p3] = hh;
        }
    template <typename T>
        typename enable_if<(is_same_v<T,int> || is_same_v<T, long long>)>::type
        print_single(T x){
            if (p3 > 1 << 20)
                flush();
            if (x < 0)
                buf2[++p3] = '-', x = -x;
            do
            {
                a[++p] = x % 10 + '0';
            } while (x /= 10);
            do
            {
                buf2[++p3] = a[p];
            } while (--p);
            buf2[++p3] = hh;
        }
    template <typename T>
        typename enable_if<is_same_v<T,string>>::type
        print_single(T x){
            if(p3>1<<20) flush();
            for(char ch:x){
                buf2[++p3]=ch;
            }
            buf2[++p3]=hh;
        }
    template <typename T, typename... T2>
        inline void print(T x, T2... oth)
        {
            print_single(x);   
            print(oth...);
        }
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define ll long long
#define pII pair<int,int>
#define lowbit(x) x&(-x)
#define ls(p) p<<1
#define rs(p) p<<1|1
mt19937 Rand(time(nullptr));
//===================================================================
// #define ONLINE_JUDGE 1
int main(){
//===================================================================
#ifndef ONLINE_JUDGE
    freopen("/home/zero/test/OI/in.in","r", stdin);
    freopen("/home/zero/test/OI/out.out","w", stdout);
#endif // !ONLINE_JUDGE
//===================================================================





    
//===================================================================
    return 0;
}
