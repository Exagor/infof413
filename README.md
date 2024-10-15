# Infof413 assignement

It was asked to do a number of comparisons analysis of two algorithms : quickselect and lazyselect.\

## Randomized selection

In randomized selection algorithms, we consider the use of random sampling for the problem of selecting the $k$th smallest element in a set $S$ of $n$ elements drawn from a totally ordered universe. We assume that the elements of S are all distinct. Let $r_s(t)$ denote the rank of an element $t$ (the $k$th smallest element has rank $k$) and let $S_i$ denote the $i$th smallest element of $S$. We extend the use of this notation to subsets of $S$ as well. Thus we seek to identify $S_k$.

### Quickselect

Quickselect is a variant of quicksort that finds the $k$th smallest of a set of items by using the same partition strategy as quicksort but then only recursing within one of the subsets of the partition, the one containing the desired value.

### Lazyselect

The idea of the algorithm is to identify two elements a and b in S such that both of the following statements hold with high probability :

1. The element $S_k$ that we seek is in $P$
2. The set $P$ of elements between $a$ and $b$ is not very large, so that we can sort $P$ inexpensively in Step 17.

We examine how either of these requirements could fail. We focus on the most interesting case when $k \in [n^{\frac{1}{4}},n-n^{\frac{1}{4}}]$, so that $P=\{ y \in S \ | \ a \leq y \leq b\}$. The  analysis for the other two cases of Step 7-16 is similar.\
If the element $a$ is greater than $S_k$ (or if $b$ is smaller than or equal to $S_k$), we fail because $P$ does not contain $S_k$. For this to happen, fewer than $l$ of the samples in R should be smaller than $S_k$ (respectively, at least $h$ of the random samples should be smaller than $S_k$).\
The second type of failure occurs when $P$ is too big