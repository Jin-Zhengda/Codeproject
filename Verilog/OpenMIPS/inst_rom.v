`include "define.v"

module inst_rom(
    input wire ce,
    input wire[`InstAddrBus] addr,
    output reg[`InstBus] inst
);

reg[`InstBus] inst_mem[0: `InstMemNum - 1];

initial begin
    $readmemh("inst_mem.data", inst_mem);
end

always @(*) begin
    if (ce == `ChipDisable)
        inst <= `ZeroWord;
    else 
        inst <= inst_mem[addr[`InstMemNumLog2 + 1: 2]];
end

endmodule