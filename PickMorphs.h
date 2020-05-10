#include <array>
#include <vector>

std::array<int, 4> pickMorphs(const std::vector<float> & weights)
{
	std::array <float, 4> value = {-1, -1, -1, -1}; /** Array of maximum values sorted ascending. */
	std::array <int, 4> index = {-1, -1, -1, -1};	/** Array of indexes of maximum values. */
	int idx = 0;

	for(const auto & p : weights)
	{
		// Checking if value is from range [0,1]
		if( p >= 0 && p <= 1)
		{
			// Iterating through value array
			for(int i = 0; i < 4; i++)
			{
				// If true:	inserting p into value array providing ascending sorting
				// Else:	breaking inner loop because value array is sorted ascending, 
				//			so further numbers are also greater then p
				if(value[i] < p)
				{
					if( i > 0)
					{
						value[i - 1] = value[i];
						index[i - 1] = index[i];
					}
					value[i] = p;
					index[i] = idx;
				}
				else
					break;
			}
		}

		idx++;
	}

	return index;
}
