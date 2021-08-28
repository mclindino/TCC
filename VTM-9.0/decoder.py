#!/usr/bin/python

import sys
import argparse
import os
import pandas as pd 
from tkinter import *

def main():
	parser = argparse.ArgumentParser() 
	parser.add_argument('--videoname', '-v', help='Nome do video')
	parser.add_argument('--binary', '-b', help='Nome da pasta com os binstreams', default='video_bin/')
	parser.add_argument('--qp', help='Parametro de Quantizacao', default='22')
	parser.add_argument('--file, -f', help='Arquivo', default='Teste')

	args = parser.parse_args()
	
	yellow = '\033[33m'
	reset = '\033[0;0m'
	green = '\033[0;32m'


	print(yellow + 'Compilando o codigo...' + reset)
	os.system('./make.sh')

	csv_names = args.videoname + '_' + args.qp + '_normal'
	print('Decodificando video ' + yellow + args.videoname + reset + ' QP ' + yellow + args.qp + reset)
	decoder = './bin/DecoderAppStaticd -b ' + args.binary + csv_names + '.bin -o ' + args.videoname + '.yuv'
	
	os.system(decoder)
	os.system('rm ' + args.videoname + '.yuv')
	os.system('mv visualizar.csv ' + csv_names + '.csv')
	print(green + 'Decodificação pronto!' + reset)
	return 0

if __name__ == '__main__':
    sys.exit(main())