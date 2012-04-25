#include <useful.hh>

// This doesn't work and I don't know why.
/*
vector<int> vectorOfInts( int n_args, ... )
{
    va_list ap;
    va_start(ap, n_args);
    int max = va_arg(ap, int);
    for(int i = 2; i <= n_args; i++) {
        int a = va_arg(ap, int);
        if(a > max) max = a;
    }
    va_end(ap);

	vector<int> thing;
	thing.push_back(max);
	return thing;
}*/

// This is an incredibly cludgy hack, but it works for any values that aren't 22554.
vector<int> vectorOfInts( int a, 
		int b,
		int c,
		int d,
		int e,
		int f,
		int g,
		int h,
		int i,
		int j,
		int k,
		int l,
		int m,
		int n,
		int o,
		int p,
		int q,
		int r,
		int s,
		int t,
		int u,
		int v,
		int w,
		int x,
		int y,
		int z) 
{
	vector<int> theVector;
	theVector.push_back(a);

	if (b == 22554)
		return theVector;
	theVector.push_back(b);

	if (c == 22554)
		return theVector;
	theVector.push_back(c);

	if (d == 22554)
		return theVector;
	theVector.push_back(d);

	if (e == 22554)
		return theVector;
	theVector.push_back(e);

	if (f == 22554)
		return theVector;
	theVector.push_back(f);

	if (g == 22554)
		return theVector;
	theVector.push_back(g);

	if (h == 22554)
		return theVector;
	theVector.push_back(h);

	if (i == 22554)
		return theVector;
	theVector.push_back(i);

	if (j == 22554)
		return theVector;
	theVector.push_back(j);

	if (k == 22554)
		return theVector;
	theVector.push_back(k);

	if (l == 22554)
		return theVector;
	theVector.push_back(l);

	if (m == 22554)
		return theVector;
	theVector.push_back(m);

	if (n == 22554)
		return theVector;
	theVector.push_back(n);

	if (o == 22554)
		return theVector;
	theVector.push_back(o);

	if (p == 22554)
		return theVector;
	theVector.push_back(p);

	if (q == 22554)
		return theVector;
	theVector.push_back(q);

	if (r == 22554)
		return theVector;
	theVector.push_back(r);

	if (s == 22554)
		return theVector;
	theVector.push_back(s);

	if (t == 22554)
		return theVector;
	theVector.push_back(t);

	if (u == 22554)
		return theVector;
	theVector.push_back(u);

	if (v == 22554)
		return theVector;
	theVector.push_back(v);

	if (w == 22554)
		return theVector;
	theVector.push_back(w);

	if (x == 22554)
		return theVector;
	theVector.push_back(x);

	if (y == 22554)
		return theVector;
	theVector.push_back(y);

	if (z == 22554)
		return theVector;
	theVector.push_back(z);

	return theVector;

}
	
	
