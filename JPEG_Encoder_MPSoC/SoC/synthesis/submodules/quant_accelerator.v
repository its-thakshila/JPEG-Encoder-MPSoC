module quant_accelerator (
    input  wire signed [31:0] dataa,
    input  wire signed [31:0] datab,
    output wire signed [31:0] result
);

    // Multiply, add, and arithmetic bit-shift right
    assign result = ((dataa * datab) + 32'h4000) >>> 15;

endmodule