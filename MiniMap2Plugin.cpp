#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MiniMap2Plugin.h"

void MiniMap2Plugin::input(std::string file) {
   readParameterFile(file);
}

void MiniMap2Plugin::run() {}

void MiniMap2Plugin::output(std::string file) {
       	std::string outputfile = file;
	//#minimap2 -ax map-ont data/genome.fasta data/reads.fastq -o ONTaln.sam
	std::string myCommand = "minimap2 -ax map-ont "+PluginManager::addPrefix(myParameters["database"])+" "+PluginManager::addPrefix(myParameters["reads"])+" >& "+file;
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<MiniMap2Plugin> MiniMap2PluginProxy = PluginProxy<MiniMap2Plugin>("MiniMap2", PluginManager::getInstance());
