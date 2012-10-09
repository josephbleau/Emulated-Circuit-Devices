#include "emucirc.h"

unsigned most_sig_dig(const std::vector<bool>& in)
{
	for(int i = in.size()-1; i >= 0; i--)
		if(in.at(i))
			return (unsigned) i;

	return 0;
}

std::vector<bool> converge(const std::vector<bool>& a, 
                           const std::vector<bool>& b)
{
	std::vector<bool> out;
	out.insert(out.begin(), out.end(), ((std::vector<bool>) a).end());
	out.insert(out.begin(), out.end(), ((std::vector<bool>) b).end());
	return out;
}

std::vector<bool> andgate(const std::vector<bool>& in)
{
	std::vector<bool> out;
	out.push_back(0);
	
	for(unsigned i = 0; i < in.size(); i++)
	{
		if(!in[i]){
			return out;
		}
	}
	
	out[0] = true;
	return out;
}

std::vector<bool> notgate(const std::vector<bool>& in)
{
	std::vector<bool> out;
	for(unsigned i = 0; i < in.size(); i++)
	{
		out.push_back(!in[i]);
	}
	return out;
}

std::vector<bool> orgate(const std::vector<bool>& in)
{
	std::vector<bool> out;
	out.push_back(1);
	for(unsigned i = 0; i < in.size(); i++)
	{
		if(in[i])
			return out;
	}
	
	out[0] = 0;
	return out;
}

std::vector<bool> encoder(const std::vector<bool>& in)
{
	double out_sz = log2(in.size());
	if(out_sz - (long) out_sz >= 0)
		out_sz++;

	std::vector<bool> out((size_t)out_sz, 0);

	unsigned sigdig = most_sig_dig(in);
	for(int i = out.size()-1; i >= 0; i--)
	{
		int bit = (sigdig >> i) & 1;
		out.at(i) = (bool) bit;
	}

	return out;
}

std::vector<bool> decoder(const std::vector<bool>& in)
{
	double out_sz = pow((double) 2, (double)in.size());
	std::vector<bool> out((size_t)out_sz, 0);

	int idx = 1;
	for(int i = 0; i < (int) in.size(); i++)
		idx += (in[i]) ? (int) pow(2.0L, i) : 0;

	out[idx-1] = true;
	return out;
}


std::vector<bool> mux(const std::vector<bool>& in, const std::vector<bool>& sw)
{
	std::vector<bool> out;
	int sigdig = most_sig_dig(decoder(sw));
	out.push_back(in[sigdig]);
	return out;
}
