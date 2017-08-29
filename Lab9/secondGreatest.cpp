//Evan Heaton
//CS216
//Lab9

int second_greatest(int* data, int size)
{
	if (size == 0)
		return -1;
	const int NEG_INF = -2147483648;
	int greatest=data[0];
	int sec_greatest=NEG_INF;
	for (int i=0;i<size;i++) //Find the greatest value
	{
		if (data[i] > greatest)
			greatest = data[i];
	}
	for (int i=0;i<size;i++) //Find the greatest value that isn't the greatest value found in the last loop
	{
		if (data[i] > sec_greatest && data[i] != greatest)
			sec_greatest = data[i];
	}
	
	if (sec_greatest == NEG_INF)
		return greatest;
	else
		return sec_greatest;	
}
