#include "sip.h"

static struct net_device *dev;

void sig_int(int num)
{
	close(dev->s);
	exit(0);
}


int main(int argc, char* argv[])
{
	
	struct skbuff *skb=NULL;
	printf("main %s\n", __TIME__);
	signal( SIGINT,sig_int);
	dev = sip_init();
	while(1){
		skb = NULL;
		dev->input(skb, dev);
		usleep(1);
		}
	close(dev->s);

	
	return 0;
}

