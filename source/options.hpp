#ifndef _OPTIONS_H
#define _OPTIONS_H 1

#include <cfloat>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

const string HELP_CONTACT = "https://github.com/suhrig/arriba/";
const string MANUAL_URL = "https://arriba.readthedocs.io/";
const string ARRIBA_VERSION = "1.2.0";

string wrap_help(const string& option, const string& text, const unsigned short int max_line_width = 80);

bool output_directory_exists(const string& output_file);

bool validate_int(const char* optarg, int& value, const int min_value = INT_MIN, const int max_value = INT_MAX);
bool validate_int(const char* optarg, unsigned int& value, const unsigned int min_value = 0, const unsigned int max_value = INT_MAX);
bool validate_float(const char* optarg, float& value, const float min_value = FLT_MIN, const float max_value = FLT_MAX);

struct options_t {
	string chimeric_bam_file;
	string rna_bam_file;
	string genomic_breakpoints_file;
	unsigned int max_genomic_breakpoint_distance;
	string gene_annotation_file;
	string exon_annotation_file;
	string known_fusions_file;
	string output_file;
	string discarded_output_file;
	string assembly_file;
	string blacklist_file;
	string interesting_contigs;
	string viral_contigs;
	unsigned int top_viral_contigs;
	float viral_contig_min_covered_fraction;
	unsigned int homopolymer_length;
	unsigned int min_read_through_distance;
	unordered_map<string,bool> filters;
	float evalue_cutoff;
	unsigned int min_support;
	float max_mismapper_fraction;
	float max_homolog_identity;
	unsigned int min_anchor_length;
	bool print_supporting_reads;
	bool print_supporting_reads_for_discarded_fusions;
	bool print_fusion_sequence;
	bool print_fusion_sequence_for_discarded_fusions;
	bool print_peptide_sequence;
	bool print_peptide_sequence_for_discarded_fusions;
	float max_kmer_content;
	unsigned int fragment_length;
	string gtf_features;
	strandedness_t strandedness;
	unsigned int min_spliced_events;
	float mismatch_pvalue_cutoff;
	unsigned int subsampling_threshold;
	float high_expression_quantile;
	float exonic_fraction;
	bool external_duplicate_marking;
};

options_t parse_arguments(int argc, char **argv);

#endif /* _OPTIONS_H */
