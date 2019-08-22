import "pe"
import "boo"

rule hello_world{
    condition:
        boo.fuzzy(0,50)
}