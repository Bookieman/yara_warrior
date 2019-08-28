git clone --recursive https://github.com/VirusTotal/yara-python
cd yara-python/yara/libyara/modules/
mkdir deps
mkdir deps/ssdeep/
git clone --branch release-2.14.1 https://github.com/ssdeep-project/ssdeep.git deps/ssdeep

