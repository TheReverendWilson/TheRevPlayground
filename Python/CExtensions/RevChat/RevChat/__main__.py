import sys
import argparse

import revchatclient
import revchatserver
# TODO: Follow github link below for some guidance on socket chat client-server program
# https://github.com/pranavdheer/Real-time-chat-application-in-c/blob/master/server.c

SERVER_TYPE = 'SERVER_TYPE'
CLIENT_TYPE = 'CLIENT_TYPE'

def main(typ: str):
    
    revchatclient.test_client()
    revchatserver.test_server()
    return 0

if __name__ == '__main__':
    parser = argparse.ArgumentPArser()
    parser.add_argument('-s', '--server',help='will run a server instance',action='store_true')
    parser.add_argument('-c', '--client',help='will run a client instance',action='store_true')
    args = parser.parse_args()
    if args.server:
        typ = SERVER_TYPE
    elif args.client:
        typ = CLIENT_TYPE
    else:
        raise ValueError('No ChatApp Type supplied.')
    sys.exit(main())
