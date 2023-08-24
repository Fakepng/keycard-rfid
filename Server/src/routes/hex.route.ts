/**
 * @openapi
 * /hex:
 *   post:
 *     summary: HEX.
 *     tags:
 *       - HEX
 *     responses:
 *       200:
 *         description: Hello!
 *
 */

import { Router } from "express";

import { hex } from "../controllers/hex.controller";

const router = Router();

router.post("/", hex);

export default router;
