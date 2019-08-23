import "pe"
import "boo"

rule HOT_FUZZ{
    condition:
        // boo.fuzzy(pe.sections[0].raw_data_offset, pe.sections[2].raw_data_offset - pe.sections[1].raw_data_offset - pe.sections[0].raw_data_offset)
        
        for any i in (0..pe.number_of_sections - 1):(
            90 <= boo.fuzzy_cmp("48:rQ7BzU7BzJIBUF9OP9QzS3CIiNji2gJsoiOdvgz:r6Oil9+S3CosoFdC",boo.fuzzy(pe.sections[i].raw_data_offset, pe.sections[i].raw_data_size))
        )

        // boo.fuzzy_cmp("48:rQ7BzlTmWIBUF9OP9QzS3CIiNji2gJsoiOdvgz:r6lAl9+S3CosoFdC", "48:rQ7BzU7BzJIBUF9OP9QzS3CIiNji2gJsoiOdvgz:r6Oil9+S3CosoFdC")

}