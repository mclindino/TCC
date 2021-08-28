#!/usr/bin/python
from subprocess import call
import os
import smtplib
import argparse
import sys

def main():
	parser = argparse.ArgumentParser() 
	parser.add_argument('--videoname', '-v', help='Nome do video')
	parser.add_argument('--quantization', '-qp', help='Parametro de Quantizacao')

	parser.add_argument('--binary', '-b', help='Nome da pasta com os binstreams', default='video_bin/')
	parser.add_argument('--tsResults', '-ts', help='Pasta dos resultados de tempo', default='out_VTM/')
	parser.add_argument('--fileOut', '-f', help='Nome do arquivo', default='Teste')
	parser.add_argument('--thread', '-t', help='Thread especifica', default='2', type=str)
	parser.add_argument('--compile', '-c', help='Compila o codigo', default=True)
	parser.add_argument('--frames', '-gop', help='Frames a serem codificados', default='8')

	args = parser.parse_args()

	yellow = '\033[33m'
	reset = '\033[0;0m'
	green = '\033[0;32m'

	qps = args.quantization.split(',')
	
	if args.compile:
		print(yellow + 'Compilando o codigo...' + reset)
		os.system('./make.sh')

	for q in qps:
		in_file = '/home/lindino/Documentos/rawVideos/BasketballPass_416x240_50.yuv'
		cmd = "taskset -c " + args.thread  + " ./bin/EncoderAppStaticd -c cfg/encoder_randomaccess_vtm.cfg -c cfg/per-sequence/" + args.videoname + ".cfg --FramesToBeEncoded=" + args.frames + " --QP=" + q + \
			  " --SIMD=SCALAR --InputFile=" + in_file + " --VideoName=" + args.videoname + " --BitstreamFile=" + args.binary + args.videoname + "_" + q + "_" + args.fileOut  + " > " + args.tsResults + args.videoname + "_" + q + "_" + args.fileOut + ".txt"


		print(yellow + 'Codificando o video ' + args.videoname + ' QP ' + q + reset)
		os.system(cmd)
	print(green + 'Done Simulation' + reset)
	return 0

if __name__ == '__main__':
    sys.exit(main())
