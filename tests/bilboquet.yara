import "pe"
import "ssdeep"

rule HOT_FUZZ{
    condition:       
        for any i in (0..pe.number_of_sections - 1):(
            90 <= ssdeep.compare("48:rQ7BzU7BzJIBUF9OP9QzS3CIiNji2gJsoiOdvgz:r6Oil9+S3CosoFdC", ssdeep.hash(pe.sections[i].raw_data_offset, pe.sections[i].raw_data_size))
        )
}