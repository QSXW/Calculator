void qsort(int *s, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	else
	{
		int i = left;
		int j = right;
		int base = s[left]; /* take the first number as the cardinal number; */
		
		while (i < j)
		{
			while (i < j && s[j] > base) /* find the index of minimum */
			{
				j--;
			}
			if (i < j)
			{
				s[i++] = s[j];
			}
			while (i < j && s[i] < base) /* find the index of maximum */
			{
				i++;
			}
			if (i < j)
			{
				s[j--] = s[i];
			}
		}
		s[i] = base; 
		qsort(s, left, i - 1);
		qsort(s, i + 1, right);
	}
}
