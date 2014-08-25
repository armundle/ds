#ifndef MSORT_H_
#define MSORT_H_

void merge(int a[], int begin, int mid, int end);

void mSort(int a[], int begin, int end)
{
	//Stop when we have only one element
	if(begin < end)
	{
		int mid = (begin + end)/2;

		mSort(a, begin, end);
		mSort(a, begin+1, end);

		//Merge the array
		merge(a,begin,mid,end);
	}

}

void merge(int a[], int begin, int mid, int end)
{
	int i,j,k;
	int *b = new int[end-begin+1];

	i = begin;
	j = mid+1;
	k = 0;

	//if the element in the first half is smaller than the one in the second half,
	//store in the tmpe array; else store the element from the second half;
	while((i<=mid) && (j<=end))
	{
		if(a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}
	
	if(i < mid) //all the elements in the first half of the array were not transferred;
	{
		for(k=i; k <=mid; k++)
		{
			b[k] = a[i];
		}
	}
	else
	{
		for(k=j; k<=end; k++)
		{
			b[k]=a[j];
		}
	}

	for(k=0; k <= (end - begin); k++)
	{
		a[k+begin] = b[k];
	}

	delete []b;
}

#endif //MSORT_H
